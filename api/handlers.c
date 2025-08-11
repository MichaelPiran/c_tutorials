#include "handlers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

#define POST_BUFFER_SIZE 4096



int send_json(struct MHD_Connection *connection, const char *json, int status_code) {
  struct MHD_Response *response = MHD_create_response_from_buffer(strlen(json), (void *)json, MHD_RESPMEM_MUST_COPY);
  MHD_add_response_header(response, "Content-Type", "application/json");
  int ret = MHD_queue_response(connection, status_code, response);
  MHD_destroy_response(response);
  return ret;
}

int handle_request(void *cls,
                   struct MHD_Connection *connection,
                   const char *url,
                   const char *method,
                   const char *version,
                   const char *upload_data, size_t *upload_data_size,
                   void **con_cls) {
  static char post_buffer[POST_BUFFER_SIZE];

  // init
  if (*con_cls == NULL){
    *con_cls = post_buffer;
    memset(post_buffer, 0 , sizeof(post_buffer));
    return MHD_YES;
  }

  if(strcmp(method, "POST") == 0 && *upload_data_size != 0){
    size_t len = *upload_data_size;
    if (len > sizeof(post_buffer) - strlen(post_buffer) - 1)
      len = sizeof(post_buffer) - strlen(post_buffer) - 1;
    strncat(post_buffer, upload_data, len);
    *upload_data_size = 0;
    return MHD_YES;
  }

  if(strcmp(method, "GET") == 0 && strcmp(url, "/api/hello") == 0){
    const char *name = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "name");
    if (name) {
      char response[256];
      snprintf(response, sizeof(response), "{\"message\":\"Hello %s\"}", name);
      return send_json(connection, response, MHD_HTTP_OK);
    } else {
      return send_json(connection, "{\"message\":\"Hello World\"}", MHD_HTTP_OK);
    }

  } else if(strcmp(method, "POST") == 0 && strcmp(url, "/api/data") == 0){
    cJSON *root = cJSON_Parse(post_buffer);
    if (!root) {
      return send_json(connection, "{\"error\":\"Invalid JSON\"}", MHD_HTTP_BAD_REQUEST);
    }
    cJSON *name = cJSON_GetObjectItemCaseSensitive(root, "name");
    if (cJSON_IsString(name) && name->valuestring != NULL) {
      char response[256];
      snprintf(response, sizeof(response), "{\"status\":\"ok\",\"name\":\"%s\"}", name->valuestring);
      cJSON_Delete(root);
      return send_json(connection, response, MHD_HTTP_OK);
    } else {
      cJSON_Delete(root);
      return send_json(connection, "{\"error\":\"Missing 'name' field\"}", MHD_HTTP_BAD_REQUEST);
    }
  } else {
    return send_json(connection, "{\"error\":\"Not Found\"}", MHD_HTTP_NOT_FOUND);
  }
}
