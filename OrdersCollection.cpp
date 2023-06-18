#include "OrdersCollection.h"

void OrdersCollection::readCollectionFromFile(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs)
	{
		throw std::runtime_error("Couldn't open orders file!");
	}
	Order s;

	unsigned _id;

	ifs.read((char*)&_id, sizeof(_id));

	Address ad1;

	//deserialization of struct Address
	int ad1NameLength;
	ifs.read((char*)&ad1NameLength, sizeof(int));
	char* ad1Name = new char[ad1NameLength+1];
	ifs.read(ad1Name, ad1NameLength);
	ad1.name = ad1Name;
	delete[] ad1Name;

	ifs.read((char*)&ad1.x, sizeof(int));

	ifs.read((char*)&ad1.y, sizeof(int));

	int ad1NoteLength;

	ifs.read((char*)&ad1NoteLength, sizeof(int));

	char* ad1Note = new char[ad1NoteLength+1];
	ifs.read(ad1Note, ad1NoteLength);
	ad1.name = ad1Note;
	delete[] ad1Note;

	Address ad2;

	int ad2NameLength;

	ifs.read((char*)&ad2NameLength, sizeof(int));

	char* ad2Name = new char[ad2NameLength+1];
	ifs.read(ad2Name, ad2NameLength);
	ad2.name = ad2Name;
	delete[] ad2Name;

	ifs.read((char*)&ad2.x, sizeof(int));

	ifs.read((char*)&ad2.y, sizeof(int));

	int ad2NoteLength;

	ifs.read((char*)&ad2NoteLength, sizeof(int));

	char* ad2Note = new char[ad2NoteLength+1];
	ifs.read(ad2Note, ad2NoteLength);
	ad2.name = ad2Note;
	delete[] ad2Note;
	 
	Client* _client;
	ifs.read((char*)&_client, sizeof(Client*));

	Driver* _driver;
	ifs.read((char*)&_driver, sizeof(Driver*));

	size_t _minutes;
	ifs.read((char*)&_minutes, sizeof(size_t));

	OrderState _state;
	ifs.read((char*)&_state, sizeof(OrderState));

	size_t _cost;
	ifs.read((char*)&_cost, sizeof(size_t));

	short _passengers;
	ifs.read((char*)&_passengers, sizeof(short));

	MyString _desc;
	int descriptionLength;

	ifs.read((char*)&descriptionLength, sizeof(int));

	char* descriptionn = new char[descriptionLength+1];
	ifs.read(descriptionn, descriptionLength);
	_desc = descriptionn;
	delete[] descriptionn;
		
	ifs.close();

	s.setIdFromFile(_id);
	s.setStart(ad1);
	s.setDest(ad2);
	s.setClient(_client);
	s.setDriver(_driver);
	s.setMinutes(_minutes);
	s.setOrderState(_state);
	s.setCost(_cost);
	s.setPassengers(_passengers);
	s.setDescription(_desc);

	this->collection.pushBack(&s);
}

void OrdersCollection::writeCollectionToFile(const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::binary | std::ios::trunc);
	if (!ofs)
	{
		throw std::runtime_error("Couldn't open orders file!");
	}
	
	for (int i = 0; i < this->collection.getSize(); i++)
	{
		ofs.write((const char*)this->collection[i]->getId(), sizeof(unsigned));
		
		//serialization of Address
		ofs.write((const char*)this->collection[i]->getStart().name.length(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getStart().name.c_str(), this->collection[i]->getStart().name.length());
		ofs.write((const char*)this->collection[i]->getStart().x, sizeof(int));
		ofs.write((const char*)this->collection[i]->getStart().y, sizeof(int));
		ofs.write((const char*)this->collection[i]->getStart().note.length(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getStart().note.c_str(), this->collection[i]->getStart().note.length());
		//
		ofs.write((const char*)this->collection[i]->getDest().name.length(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getDest().name.c_str(), this->collection[i]->getDest().name.length());
		ofs.write((const char*)this->collection[i]->getDest().x, sizeof(int));
		ofs.write((const char*)this->collection[i]->getDest().y, sizeof(int));
		ofs.write((const char*)this->collection[i]->getDest().note.length(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getDest().note.c_str(), this->collection[i]->getDest().note.length());

		ofs.write((const char*)this->collection[i]->getClient(), sizeof(Client*));
		ofs.write((const char*)this->collection[i]->getDriver(), sizeof(Driver*));
	
		ofs.write((const char*)this->collection[i]->getMinutes(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getOrderState(), sizeof(OrderState));
		ofs.write((const char*)this->collection[i]->getCost(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getPassengers(), sizeof(short));
		
		ofs.write((const char*)this->collection[i]->getDescription().length(), sizeof(size_t));
		ofs.write((const char*)this->collection[i]->getDescription().c_str(), this->collection[i]->getDescription().length());
	}
}
