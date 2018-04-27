#ifndef _H_FINIX_CAPTURE_
#define _H_FINIX_CAPTURE_

#include <tins/tins.h>
#include "finix_config.hpp"
#include "finix_format.hpp"
#include "finix_exporter.hpp"
using namespace Tins;


namespace finix {
class FinixCapture: public FinixExporter {
    public:
        FinixCapture (FinixConfig &finix_config): \
            m_finix_config(finix_config), 
            FinixExporter(finix_config.get_zmq_conn_string(), finix_config.get_debug()) {
        };

        static bool compute_packets(const PDU& pdu);
        void run();

    private:
        std::string get_frame_type(const PDU& pdu);
        std::string get_frame_subtype(const PDU& pdu);
        std::string get_src_addr(std::string frame_type, const PDU& pdu);
        std::string get_dst_addr(std::string frame_type, const PDU& pdu);

        int32_t get_dbm_signal(const PDU& pdu);
        int32_t get_signal_quality(const PDU& pdu);
        int32_t get_antenna(const PDU& pdu);
        int32_t get_db_signal(const PDU& pdu);
        int32_t get_dbm_noise(const PDU& pdu);

        std::string _get_mgmt_subtype(int frame_byte);
        std::string _get_ctrl_subtype(int frame_byte);
        std::string _get_data_subtype(int frame_byte);
        std::string _get_control_src_addr(int frame_byte, const PDU& pdu);

        bool process_packets(const PDU& pdu);
        bool invalid_wlan_packet(const PDU& pdu);
        long long get_current_timestamp();
        
        FinixConfig m_finix_config;
};
}
#endif