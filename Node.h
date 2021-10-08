#include <iostream>
#include <iterator>
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
        
        void receive(DataFrame frame)
        {   
            string str(frame.ReadMessage(mac_addr));
            if (str.compare("") == 0)
                return;
            cout << "Data Received by Node " << device_id << " is '" << 
                    str << "'" << endl;
        }
        
        template <size_t n>
        void transmit(uint64_t (&dest_mac_addr)[n])
        {  
           if (n != 6)
                return;
            
           string str(device_id); 
           DataFrame frame("Greetings from node " + str, mac_addr, dest_mac_addr);
           
           vector<Link>::iterator ptr;

           for (ptr = connected_links.begin(); ptr < connected_links.end(); ptr++)
                ptr.sendToLink(frame);
        }     
};


