#include <arpa/inet.h>
#include <errno.h>
#include <ifaddrs.h>
#include <memory.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <optional>

// TODO
// Use spdlog

const char* const IP{"192.168.10.1"};
const char* const TO_PORT{"8889"};
const in_port_t FROM_PORT{9000};

namespace ctello
{
class Tello
{
public:
    Tello();
    bool Bind();
    bool SendCommand(const std::string& command);
    std::optional<std::string> ReceiveResponse();

private:
    int m_sockfd{0};
    sockaddr_storage m_dest_addr{};
};
}  // namespace ctello

