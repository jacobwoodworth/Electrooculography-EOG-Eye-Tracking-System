#include <iostream>
#include <cstring>
#include <boost/asio.hpp>

using namespace boost;

void configureSerialPort(asio::serial_port &port, const std::string& portname, unsigned int baudrate) {
    port.open(portname);
    port.set_option(asio::serial_port_base::baud_rate(baudrate));
}

std::string readFromSerialPort(asio::serial_port& serial) {
    char buffer[100];
    system::error_code ec;
    size_t len = asio::read(serial, asio::buffer(buffer), ec);
    if (ec) {
        std::cerr << ec.message() << std::endl;
        return "";
    }
    return std::string(buffer, len);
}

int main() {
    asio::io_service io;
    asio::serial_port port(io);

    try {
        configureSerialPort(port, "", 9600);
    }

    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::string response;


        response = readFromSerialPort(port);
        if (!response.empty()) {
            std::cout<< response << std::endl;
        }
    port.close();

    return 0;
}