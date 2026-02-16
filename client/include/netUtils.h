#ifndef NETWORKUTILS_H
#define NETWORKUTILS_H

#include <cstdint>
#include <string>
#include <vector>

namespace NetworkUtils {

enum class MessageType {
    REQUEST,
    REPLY,
    ACK,
    SYNC,
    ACK_SYNC
};

struct MessageId {
    uint32_t id;
    uint32_t ip4Addr;
    uint16_t port;
}; 

struct Message {
    MessageType messageType;
    MessageId messageId;
    std::string content;
};

class SocketConnection {
private:

    uint32_t ip4Addr; // IPv4 as 4-byte int
    uint16_t port;

public:
    SocketConnection(uint32_t ip4Addr, uint16_t port);
    ~SocketConnection();

    int connectToServer(); // returns sockfd

    // Sends raw bytes over the connected socket 
    bool sendMessage(const std::vector<char>& data); 
    // Receives raw bytes from the connected socket
    std::vector<char> receiveMessage(); 
};

class MessageTransceiver {
private:
    int sockfd;

public:
    MessageTransceiver(int sockfd);
    ~MessageTransceiver();

    std::vector<char> serialize(const Message& message);
    Message deserialize(const std::vector<char>& data);
};

} // namespace NetworkUtils

#endif // NETWORKUTILS_H
