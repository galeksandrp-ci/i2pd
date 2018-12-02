#ifndef TIMESTAMP_H__
#define TIMESTAMP_H__

#include <inttypes.h>
#include <thread>
#include <vector>
#include <string>
#include <boost/asio.hpp>

namespace i2p
{
namespace util
{
	uint64_t GetMillisecondsSinceEpoch ();
	uint32_t GetHoursSinceEpoch ();
	uint64_t GetSecondsSinceEpoch ();

	class NTPTimeSync
	{
		public:

			NTPTimeSync ();
			~NTPTimeSync ();

			void Start ();
        	void Stop ();

		private:
			
			void Run ();
			void Sync ();		

		private:

			bool m_IsRunning;
       		std::unique_ptr<std::thread> m_Thread;
			boost::asio::io_service m_Service;
			boost::asio::deadline_timer m_Timer;
			int m_SyncInterval;
			std::vector<std::string> m_NTPServersList;
	};
}
}

#endif

