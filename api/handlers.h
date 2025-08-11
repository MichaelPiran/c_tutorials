#ifndef HANDLERS_H
#define HANDLERS_H

#include <microhttpd.h>

int send_json(
    struct MHD_Connection *connection,
    const char *json, 
    int staus_code
  );
int handle_request(
    void *cls,
    struct MHD_Connection *connection,
    const char *url,
    const char *method,
    const char *version,
    const char *upload_data, size_t *upload_data_size,
    void **con_cls
  );

#endif
