#include "symtab.h"
#include "scanner.h"

Attributes& Symbol_table::get(string name){
	auto symbol = this->sym_tab.find(name);
	if(symbol != this->sym_tab.end()){
		return symbol->second;
	}
	error("get: undefined Symbol_table");
}

void Symbol_table::set(string name, double nv){
	auto symbol = this->sym_tab.find(name);
	if(symbol == this->sym_tab.end())
		error("set: undefined Symbol_table");
	
	else if(!(symbol->second.is_const)){
		symbol->second.value = nv;
	}
	else
		error("cannot change constant");
}

bool Symbol_table::is_declared(string name){
	auto symbol = this->sym_tab.find(name);
	if(symbol == this->sym_tab.end())
		return false;
	return true;
}

void Symbol_table::declare(string name, double nv, bool ic){
	if(is_declared(name)) error("name declared twice");
	Attributes attribute{nv, ic};
	this->sym_tab.insert(make_pair(name, attribute));
}

