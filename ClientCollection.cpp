#include "ClientCollection.h"

void ClientCollection::readCollectionFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs)
	{
		throw std::runtime_error("Couldn't open clients file!");
	}

		char line[1024];
		if (ifs.is_open())
		{
			ifs.seekg(0, std::ios::end);
			if (ifs.tellg() == 0)
			{
				throw std::runtime_error("File empty");
			}
			ifs.seekg(0, std::ios::beg);

			while (!ifs.eof())
			{
				Client s;
				ifs.getline(line, 1024);
				std::stringstream ss(line);
				MyString word;
				ss >> word; //first word-0

				if (ss >> word)
				{
					try
					{
						s.setUsername(word);
					}
					catch (std::invalid_argument& exc)
					{
						std::cout << "Couldn't read username from file!" << std::endl;
						throw;
					}
				}

				if (ss >> word)
				{
					try
					{
						s.setPassword(word);
					}
					catch (std::invalid_argument& exc)
					{
						std::cout << "Couldn't read password from file!" << std::endl;
						throw;
					}
				}

				if (ss >> word)
				{

					try
					{
						s.setFirstName(word);
					}
					catch (std::invalid_argument& exc)
					{
						std::cout << "Couldn't read first name from file!" << std::endl;
						throw;
					}
				}

				if (ss >> word)
				{

					try
					{
						s.setLastName(word);
					}
					catch (std::invalid_argument& exc)
					{
						std::cout << "Couldn't read last name from file!" << std::endl;
						throw;
					}
				}
				this->collection.pushBack(SharedPtr<Client>(new Client(s)));
			}
		}
		ifs.close();
		
}

void ClientCollection::writeCollectionToFile(const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::trunc);
	if (!ofs)
	{
		throw std::runtime_error("Couldn't open clients file!");
	}
	for (int i = 0; i < this->collection.getSize(); i++)
	{
		
		ofs << 0 << " " << this->collection[i]->getUsername() << " " << this->collection[i]->getPassword() << " " << this->collection[i]->getFirstName() << " " <<
			this->collection[i]->getLastName();
		if (i < this->collection.getSize() - 1)
		{
			ofs << std::endl;
		}
	}
	ofs.close();
}
