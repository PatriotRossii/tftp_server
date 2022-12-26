#include <iostream>

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <tftp_common/packets.hpp>
#include <tftp_common/serialization.hpp>

using boost::asio::ip::udp;

int main() {
	try {
		boost::asio::io_context io_context;
		udp::socket socket(io_context, udp::endpoint(udp::v4(), 69));

		for (;;) {
			boost::array<char, 1024> recv_buf;
			udp::endpoint remote_endpoint;
			socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);

			std::vector<char> send_buffer;
			tftp_common::packets::error err = {
				.ErrorCode = 0,
				.ErrMsg = "UNIMPLEMENTED"
			};
			err.serialize(std::back_inserter(send_buffer));
			socket.send_to(boost::asio::buffer(send_buffer), remote_endpoint);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}