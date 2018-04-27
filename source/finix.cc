#include <iostream>
#include <string>
#include "Parser.h"
#include "finix_config.hpp"
#include "finix_capture.hpp"
using namespace finix;


int main(int argc, char* argv[])
{
    StringOption interfaceOpt('i' ,"interface"   ,true  ,"Specify Interface");
    StringOption      nameOpt('n' ,"name"        ,false ,"Specify export name (optional [default='default'])");
    StringOption    filterOpt('f' ,"pcap-filter" ,false ,"Specify pcap wlan filter (optional [default='wlan'])");
    StringOption   zmqConnOpt('z' ,"zmq-conn"    ,false ,"Specify zeromq connection (optional [default='tcp://*:70000'])");
    BoolOption       debugOpt('d' ,"debug"       ,false ,"Specify debugging (optional)");

    Parser parser;
    parser.addOption(interfaceOpt);
    parser.addOption(nameOpt);
    parser.addOption(filterOpt);
    parser.addOption(zmqConnOpt);
    parser.addOption(debugOpt);
    std::vector<std::string> otherArguments = parser.parse(argc, argv);

    FinixConfig finix_config;
    finix_config.set_interface(interfaceOpt.getValue());

    if(!filterOpt.getValue().empty())
        finix_config.set_pcap_filter(filterOpt.getValue());

    if(!zmqConnOpt.getValue().empty())
        finix_config.set_zmq_conn_string(zmqConnOpt.getValue());

    if(!nameOpt.getValue().empty())
        finix_config.set_name(nameOpt.getValue());

    if(!debugOpt.getValue())
        finix_config.set_debug(debugOpt.getValue());

    FinixCapture finix_capture(finix_config);
    finix_capture.run();

    return 0;
}