#include <iostream>
using namespace std;

static int count = 0;

class DataFrame
{
    private:
        string msg;
        int msg_seq_num;
        uint64_t src_mac_addr[6];
        uint64_t dest_mac_addr[6];
    
    public:
        DataFrame(string a, uint64_t c[], uint64_t d[])
        {
            msg = a;
            msg_seq_num = (++count);
            
            for(int i = 0; i < 5; ++i)
                src_mac_addr[i] = c[i];
            
            for(int i = 0; i < 5; ++i)
                dest_mac_addr[i] = d[i];
        }
        
        template <size_t n>
        string ReadMessage(uint64_t (&node_mac_addr)[n])
        {  
           if (n != 6)
                return "";
           
           string str(MacAddresstoString(dest_mac_addr));
           if (str.compare("FF:FF:FF:FF:FF:FF") == 0)
           {
               return msg;
           }
            
           for(int i = 0; i < 5; ++i)
           {
               if (node_mac_addr[i] != dest_mac_addr[i])
               {
                   return "";
               }
           }
           return msg;
        }
        
        template <size_t n>
        char MacAddresstoString(uint64_t (&mac_addr)[n])
        {   
            if (n != 6)
                return "";
            
            char macStr[18];
        
            snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
                mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
                
            return macStr;
        }
    
};

int main()
{   
    uint64_t src_mac_addr[6] = {1, 2, 3, 4, 5, 6};
    uint64_t dest_mac_addr[6] = {7, 8, 9, 10, 11, 12};
    
    DataFrame obj("xc", src_mac_addr, dest_mac_addr);
    
    return 0;
}
