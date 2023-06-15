#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <tftp_common/tftp_common.hpp>

#include <iostream>
#include <cstdlib>

using namespace tftp_common::packets;
using boost::asio::ip::udp;

int main() {
	try {
		boost::asio::io_context io_context;
		udp::socket socket(io_context, udp::endpoint(udp::v4(), 69));

		for (;;) {
			boost::array<std::uint8_t, 1024> recv_buf;
			udp::endpoint remote_endpoint;
			socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);

			std::vector<std::uint8_t> send_buffer(1024);
			Error err(10, "UNIMPLEMENTED");
			std::size_t packetSize = err.serialize(send_buffer.begin());
			socket.send_to(boost::asio::buffer(send_buffer, packetSize), remote_endpoint);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}