#include <stdio.h>
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

/*
consider the data is coming in a streaming with below protocol
1 byte(cmd) + 4 bytes(length of payload) + payload
the max size for the protocol frame data is 1024 bytes.

the data is comming at any size, so you need to organize them to get 
the payload data and then send it to other client by below struct
struct packet
{
    uint8_t cmd;
    uint32_t length;
    uint8_t * paylaod;
    uint8_t * paylaod1;
}
*/


/*
1, get data from socket. use a buffer1

2, 
1)buffer1 0-512 length 100, while loop to send . void get_packet_buffer
2)buffer1 0-512 length 600, wait for the data.
memcpy(buffer2+count, buffer1, 600);

3, send the data in packet buffer2 , p=(packet_t*)buffer2

*/
typedef struct packet
{
    uint8_t cmd;
    uint32_t length;
    uint8_t * payload;
}packet_t;


#define MAX_FRAGMENT_SIZE 1024
#define MAX_RECV_SIZE 1024

uint8_t recv_buff[MAX_RECV_SIZE];
uint8_t fragment_buff[MAX_FRAGMENT_SIZE];
uint32_t fragment_count;

#define MIN(x, y) x>y? y:x
void handle_recv_data(uint8_t* p_recv_buf, uint32_t recv_len)
{
    uint8_t cmd;
    uint32_t length, remain_len=MAX_FRAGMENT_SIZE-fragment_count;
    
    
    if(remain_len==0)
    
}

#define MAX_PROTOCOL_SIZE 1024
#define MAX_RECV_SIZE 1024
uint8_t data_buff[MAX_PROTOCOL_SIZE + MAX_RECV_SIZE];

void handle_fragment_data(uint8_t* data_buff, uint32_t &offset_protocol, uint32_t recv_count)
{
    
    uint32_t avail_count = MAX_PROTOCOL_SIZE - *offset_protocol + recv_count, pack_size;
    packet_t pack;
    pack.cmd = data_buff[offset_protocol];
    pack.length = *(uint32_t*)(&data_buff[offset_protocol+1]);
    
    pack_size = 5+pack.length;
    while(1)
    {
        pack_size = 5 + *(uint32_t*)(&data_buff[offset_protocol+1]);
        if(pack_size > avail_count)
            break;
        
        avail_count -= pack_size; 
        offset_protocol += pack_size;
        
    }
    if (MAX_PROTOCOL_SIZE - offset_protocol + recv_count >= pack.length + 5)
    {
        // data is enough for one frame. so do it
        packet_t * data= (data_buff+offset_protocol);
        
    }
    // how many left
    
    
}

void main()
{
    
    if((recv_count = recv(socket_desc, data_buff+MAX_PROTOCOL_SIZE, MAX_RECV_SIZE , 0))<0)
    {
        printf("receive error");
        return ;
    }
    
    // write the data into 
    handle_fragment_data(ring_buff, &ring_start, &ring_end, recv_buff, recv_count);
    
    
    
    
}
