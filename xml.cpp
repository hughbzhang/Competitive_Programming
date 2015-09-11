#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class element{
	string name;
	bool isTag;

	pair<string,string>* label;
	int numLabels;

	element* data
	int numElements;
public:
	string toString(){
		if(!isTag) return name;
		string xml = "<";
		xml+=name;
		pair<string,string>* cur = label;
		for(int x = 0;x<numLabels;x++){
			xml+=" ";
			xml+=label->first;
			xml+="=\"";
			xml+=label->second;
			xml+="\"";
			++cur;
		}
		xml+=">";

		element* curElement = data;

		for(int x = 0;x<numElements;x++){
			xml+=curElement->toString();
			++curElement;
		}

		xml+="</";
		xml+=name;
		xml+=">";
		return xml;
	}

	element(string name, bool isTag, int numLabels = 0,
		pair<string,string>* labels = NULL, int numElements = 0, element* datas = NULL){
		
		this.name = name;
		this.isTag = isTag;
		this.numLabels = numLabels
		this.label = labels;
		this.numElements = numElements;
		this.data = datas;
	}

	void makeTag(int numLabels,pair<string,string>* labels, int numElements, element* datas){
		this.isTag = true;
	}
};




abstract class Element{}


class text extends Element{
	//use parents toString
	bool isTag(){ return false; }

};

class tag extends Element{
		
	override toString(){
		string xml = "<";
		xml+=name;
		pair<string,string>* cur = label;
		for(int x = 0;x<numLabels;x++){
			xml+=" ";
			xml+=label->first;
			xml+="=\"";
			xml+=label->second;
			xml+="\"";
			++cur;
		}
		xml+=">";

		element* curElement = data;

		for(int x = 0;x<numElements;x++){
			xml+=curElement->toString();
			++curElement;
		}

		xml+="</";
		xml+=name;
		xml+=">";
		return xml;
	}
	bool isTag(){ return true; }
};






