
#include <string>
#include "finix_config.hpp"
using namespace finix;

void FinixConfig::set_interface(std::string interface) {
    m_interface = interface;
}

std::string FinixConfig::get_interface() {
    return m_interface;
}

void FinixConfig::set_debug(bool debug) {
    m_debug = debug;
}

bool FinixConfig::get_debug() {
    return m_debug;
}

void FinixConfig::set_name(std::string name) {
    m_name = name;
}

std::string FinixConfig::get_name() {
    return m_name;
}
    
void FinixConfig::set_zmq_conn_string(std::string zmq_conn_string) {
    m_zmq_conn_string = zmq_conn_string;
}

std::string FinixConfig::get_zmq_conn_string() {
    return m_zmq_conn_string;
}

void FinixConfig::set_pcap_filter(std::string pcap_filter) {
    m_pcap_filter = pcap_filter;
}

std::string FinixConfig::get_pcap_filter() {
    return m_pcap_filter;
}