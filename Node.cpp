#include <iostream>
#include <vector>
using namespace std;

static int count = 0;

class Node
{
    private:
        int device_id;
        uint64_t mac_addr[6];
        vector<Link> connected_links;
    
    public:
        Node(uint64_t b[])
        {
            device_id = (++count);
            
            for(int i = 0; i < 5; ++i)
                mac_addr[i] = b[i];
            
        }
        
        void addLink(Link link)
        {
            connected_links.push_back(link);
        }
        
        template <size_t n>
        void receive(DataFrame frame)
        {
            cout << "Data Received by Node " << device_id << " is '" << 
                    frame.ReadMessage(mac_addr) << "'" << endl;
        }
        
        template <size_t n>
        void transmit(uint64_t (&dest_mac_addr)[n])
        {  
           if (n != 6)
                return;
            
           string str(device_id); 
           DataFrame frame("Greetings from node " + str, mac_addr, dest_mac_addr);
           sendToLink(frame);
        }
        
};


