#include "lang.h"

Lang::Lang(std::string value)
{
	file_source = std::ifstream(value);
	if (!file_source.is_open()) return;
	file_source >> file;
	file_source >> imp;
	file_source >> exp;
	file_source >> save;
	file_source >> report;
	file_source >> settings;
	file_source >> lang;
	file_source >> rus;
	file_source >> eng;
	file_source >> work_time;
	file_source >> price;
	file_source >> change;
	file_source >> login;
	file_source >> theme;
	file_source >> light;
	file_source >> dark;
	file_source >> patr;
	file_source >> help;
	file_source >> view;

	file_source >> data_time;
	file_source >> data_type;
	file_source >> data_client;
	file_source >> data_computer;

	file_source >> date;
	file_source >> user;
	file_source >> time;
	file_source >> type;
	file_source >> client;
	file_source >> computer;
	file_source >> add;
	file_source >> finish;

	file_source >> CAME;
	file_source >> WAIT;
	file_source >> SIT;
	file_source >> LEAVE;

	file_source >> error;

	file_source >> Set;
	file_source >> time_start;
	file_source >> time_end;

	file_source >> nick;
	file_source >> reg;
	file_source >> suck;
	file_source >> autorez;
}
