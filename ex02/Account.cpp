#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout 
			  << " accounts:"
			  << Account::getNbAccounts()
			  << ";total:"
			  << _totalAmount
			  << ";deposits:"
			  << Account::getNbDeposits()
			  << ";withdrawals:"
			  << Account::getNbWithdrawals()
			  << std::endl;
}

Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	static int i = 0;
	_accountIndex = i;
	_nbAccounts++;
	_amount = initial_deposit;
	std::cout 
			  << " index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";created"
			  << std::endl;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	i++;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout 
			  << " index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";closed"
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";p_amount:"
			  << _amount
			  << ";deposit:"
			  << deposit;
	_amount += deposit;
	std::cout << ";amount:"
			  << checkAmount()
			  << ";nb_deposits:"
			  << &Account::getNbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	if (withdrawal <= _amount)
	{
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << " index:"
			  	  << _accountIndex
			  	  << ";p_amount:"
			  	  << checkAmount()
			  	  << ";withdrawal:"
			  	  << withdrawal;
		_amount -= withdrawal;
		std::cout << ";amount:"
			  	  << checkAmount()
			  	  << ";nb_withdrawals:"
			  	  << &Account::getNbWithdrawals
			  	  << std::endl;
		return true;
	}
	else
	{
		std::cout << " index:"
			  	  << _accountIndex
			  	  << ";p_amount:"
			  	  << checkAmount()
			  	  << ";withdrawal:refused"
			  	  << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 
			  << " index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";deposits:"
			  << _nbDeposits
			  << ";withdrawals:"
			  << _nbWithdrawals
			  << std::endl;
}

void	Account::_displayTimestamp()
{
    std::time_t	currentTime = std::time(0);
    std::tm		*localTime = std::localtime(&currentTime);

    std::cout << "["
			  << (localTime->tm_year + 1900)
              << (localTime->tm_mon + 1 < 10 ? "0" : "")
			  << localTime->tm_mon + 1
              << (localTime->tm_mday < 10 ? "0" : "")
			  << localTime->tm_mday
    		  << "_"
              << (localTime->tm_hour < 10 ? "0" : "")
			  << localTime->tm_hour
              << (localTime->tm_min < 10 ? "0" : "")
			  << localTime->tm_min
              << (localTime->tm_sec < 10 ? "0" : "")
			  << localTime->tm_sec
			  << "]";
}
