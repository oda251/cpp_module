/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:21:39 by yoda              #+#    #+#             */
/*   Updated: 2024/04/21 20:37:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int Account::getTotalAmount( void ) {
	return _totalAmount;
}
int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}
int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) {
	_nbDeposits = initial_deposit;
	_nbAccounts++;
	_totalNbDeposits += initial_deposit;
}

Account::~Account( void ) {
}

void Account::makeDeposit( int deposit ) {
}
bool Account::makeWithdrawal( int withdrawal ) {
}
int Account::checkAmount( void ) const {
}
void Account::displayStatus( void ) const {
}

public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
