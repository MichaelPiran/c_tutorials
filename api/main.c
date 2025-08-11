#include <microhttpd.h>
#include <stdio.h>
#include "handlers.h"

#define PORT 8080

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(
        MHD_USE_SELECT_INTERNALLY,  // Modalità event-driven
        PORT,
        NULL, NULL,                  // Niente controllo connessioni
        &handle_request, NULL,       // Callback per gestire richieste
        MHD_OPTION_END);

    if (daemon == NULL) {
        fprintf(stderr, "Errore: impossibile avviare il server.\n");
        return 1;
    }

    printf("Server avviato su http://localhost:%d\n", PORT);
    getchar(); // Attende invio per terminare

    MHD_stop_daemon(daemon);
    return 0;
}

