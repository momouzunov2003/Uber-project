#include "Order.h"
#include <cmath>
#include <fstream>

double Order::calculateDistance() const
{
    return sqrt(pow(dest.x-start.x,2)+pow(dest.y-start.y,2));
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Order::Order(const Address& _start, const Address& _dest, const short _passengers)
{
    setId();
    setStart(_start);
    setDest(_dest);
    setPassengers(_passengers);
    setOrderState(OrderState::Waiting);
}

Order::Order(const Address& _start, const Address& _dest, const MyString _description, const short _passengers)
{
    setId();
    setStart(_start);
    setDest(_dest);
    setDescription(_description);
    setPassengers(_passengers);
    setOrderState(OrderState::Waiting);
}

Order::Order(OrderState _state, const Address& _start, const Address& _dest, short _passengers, size_t _minutes, size_t _cost)
{
    setId();
    setOrderState(_state);
    setStart(_start);
    setDest(_dest);
    setPassengers(_passengers);
    setMinutes(_minutes);
    setCost(_cost);
}

Order::~Order()
{
    delete client;
    delete driver;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Order::setId()
{
    std::ifstream ifs(ID_FILE_NAME);
    if (!ifs.is_open())
    {
        throw std::runtime_error("Couldn't open ID file!");
    }

    unsigned num;
    ifs >> num;
    ifs.close();

    id = num + 1;

    std::ofstream ofs(ID_FILE_NAME, std::ios::trunc);
    if (!ofs.is_open())
    {
        throw std::runtime_error("Couldn't open ID file!");
    }

    ofs << num + 1;

    ofs.close();
}

void Order::setStart(const MyString _name, int _x, int _y, const MyString _note)
{
    Address s(_name, _x, _y, _note);
    start = s;
}

void Order::setStart(const Address& address)
{
    start = address;
}

void Order::setDest(const MyString _name, int _x, int _y, const MyString _note)
{
    Address s(_name, _x, _y, _note);
    dest = s;
}

void Order::setDest(const Address& address)
{
    dest = address;
}

void Order::setClient(Client* _client)
{
    client = _client;
}

void Order::setDriver(Driver* _driver)
{
    driver = _driver;
}

void Order::setMinutes(unsigned _minutes)
{
    minutes = _minutes;
}

void Order::setOrderState(OrderState _state)
{
    state = _state;
}

void Order::setCost(size_t _cost)
{
    cost = _cost;
}

void Order::setPassengers(short _passengers)
{
    passengers = _passengers;
}

void Order::setDescription(const MyString _desc)
{
    description = _desc;
}

void Order::setIdFromFile(unsigned n)
{
    id = n;
}

unsigned Order::getId()
{
    return id;
}

const Address& Order::getStart()
{
    return start;
}

const Address& Order::getDest()
{
    return dest;
}

Client* Order::getClient()
{
    return client;
}

Driver* Order::getDriver()
{
    return driver;
}

unsigned Order::getMinutes()
{
    return minutes;
}

OrderState Order::getOrderState()
{
    return state;
}

size_t Order::getCost()
{
    return cost;
}

short Order::getPassengers()
{
    return passengers;
}

const MyString Order::getDescription()
{
    return description;
}

void Order::rateDriver(short num)
{
    try
    {
        driver->setRating(num);
    }
    catch (std::invalid_argument& exc)
    {
        std::cout << "Invalid rating!" << std::endl;
        throw;
    }
}


