#ifndef TABLE_HPP
#define TABLE_HPP
#include <iostream>
#include <tuple>
#include "../client/client.hpp"
#include "../time/time.hpp"

namespace TableSpace
{
    class Table
    {
        bool status;
        Client* client;
        Time time_use;
        int cof;
        int num;
    public:
        Table(Client* _client, Time _time_use, bool _status) :
            client(_client),
            time_use(_time_use),
            status(_status) {};
        Table();

        bool get_status() const;
        Client* get_client() const;
        Time get_time() const;
        int get_cof() const;
        int get_num() const;

        void set_client(Client* client);
        void set_status(bool status);
        void set_num(int num) ;

        void left_client(Time time, Time time_start);
        void left_client(Time time);
    };
}
#endif
