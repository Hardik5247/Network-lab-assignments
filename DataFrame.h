#include <iostream>

using namespace std;

class DataFrame
{
	private:
		string msg;
	  	int msg_seq_num;
	  	uint64_t src_mac_addr[6];
	  	uint64_t dest_mac_addr[6];
	
	public:
	  	DataFrame(string a, uint64_t c[], uint64_t d[], int count1)
	  	{
			msg = a;
			msg_seq_num = (count1);

			for(int i = 0; i < 5; ++i)
			  src_mac_addr[i] = c[i];

			for(int i = 0; i < 5; ++i)
			  dest_mac_addr[i] = d[i];
	  	}
		
		/** 
		 * Function to read message from data frame. 
		 **/
	  	template <size_t n>
	  	string ReadMessage(uint64_t (&node_mac_addr)[n])
	  	{  
			string str("");

			if (n != 6)
			  return str;

			bool isBroadcast = true;
			for(int i = 0; i < 5; ++i)
			{
			  if (dest_mac_addr[i] != 0xFF)
			  	isBroadcast = false;
			}

			if (isBroadcast == false) // Message is unicast
			{ 
			  for(int i = 0; i < 5; ++i)
			  {
			    if (node_mac_addr[i] != dest_mac_addr[i])
				  return str;
			  }

			} else {
			  
			  bool isSameNode = true;

			  for(int i = 0; i < 5; ++i) // Message is broadcast
			  {
			    if (node_mac_addr[i] != src_mac_addr[i])
				  isSameNode = false;
			  }

			  if (isSameNode)
				return str;
			
			}
			return msg;
	  	}
};
