#ifndef _H_FINIX_EXPORTER_
#define _H_FINIX_EXPORTER_

#include <string>

namespace finix {
class FinixExporter {
    public:
        static void init(std::string zmq_conn_string, bool debug);
        static bool export_capture(std::string capture_data);

    private:
        bool m_connection = false;
        
};
}
#endif