#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "../cs_common/Config.hpp"
#include "../cs_common/Message.hpp"
#include "../cs_common/Session.hpp"

// Declare the global function to exist somewhere
// Is defined in Main.cpp
boost::asio::io_service& getIOService();

#include "Game.h"
#include "GameState.h"


bool playGame(){
	Game g;
	g.play();
	return dynamic_cast<WinState*>(g.getState().get()) != NULL;
}



namespace MessageASIO
{
	/**
	 *
	 */
	class Server
	{
		public:
			/**
			 * The server will listen on localhost/ip-address on the port
			 */
			Server(boost::asio::io_service& an_io_service,
			       short port)
			: 	io_service(an_io_service),
			  	acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
			  	{
				// start handling incoming connections
				handleAccept(NULL,boost::system::error_code());
			  	}

			~Server()
			{
			}

			/**
			 *	Handle any incoming connections
			 */
			void handleAccept(	MessageASIO::ServerSession* aSession,
			                  	const boost::system::error_code& error)
			{
				Message resultMsg;
				if (!error)
				{
					// Create the session that will handle the next incoming connection
					MessageASIO::ServerSession* session = new MessageASIO::ServerSession(io_service);
					// Let the acceptor wait for any new incoming connections
					// and let it call server::handle_accept on the happy occasion
					acceptor.async_accept(session->getSocket(),
					                      boost::bind(&Server::handleAccept,
					                                  this,
					                                  session,
					                                  boost::asio::placeholders::error));
					// If there is a session, start it up....
					if(aSession)
					{
						aSession->start();
						std::string msgString = playGame() ? "YOU WON THE GAME!" : "YOU LOST THE GAME!";
						resultMsg = Message(1, msgString);
						aSession->writeMessage(resultMsg);
					}
				}else
				{
					delete aSession;
					throw std::runtime_error(__PRETTY_FUNCTION__ + std::string(": ") + error.message());
				}
			}
		private:
			// Provides core I/O functionality
			// @see http://www.boost.org/doc/libs/1_40_0/doc/html/boost_asio/reference/io_service.html
			boost::asio::io_service& io_service;

			// Provides the ability to accept new connections
			// @see http://www.boost.org/doc/libs/1_40_0/doc/html/boost_asio/reference/basic_socket_acceptor.html
			boost::asio::ip::tcp::acceptor acceptor;
	}; // class Server

	class CrapsServerSession : virtual public ServerSession{
	public:
		CrapsServerSession(boost::asio::io_service& io_service) :
			MessageASIO::ServerSession( io_service)
		{
		}

		~CrapsServerSession()
		{
		}
		virtual void handleMessageRead( Message& aMessage){}
	};
}	// namespace MessageASIO



#endif // SERVER_HPP_
