/**
 *
 *  Download Upload Messaging Manager
 *
 *  Copyright (C) 2012-2013  Open-RnD Sp. z o.o. All rights reserved.
 * @verbatim
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License version 3 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License version 3
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * @endverbatim

 * @file curl-headers.h
 * @author Bartlomiej Jozwiak (bj@open-rnd.pl)
 * @date 01-04-2013
 * @brief __BRIEF_HERE_TBD__
 *
 * __DETAILS__
 */

#include <cerrno>

#include "openrnd-mutex.h"
#include "openrnd-exceptions.h"

_mutex::_mutex()
{
	RUNTIME_THROW_TEST(pthread_mutex_init(&m_, NULL) == 0);
}

_mutex::~_mutex()
{
    unlock();
    pthread_mutex_destroy(&m_);
}

void _mutex::lock()
{
	RUNTIME_THROW_TEST(pthread_mutex_lock(&m_) == 0);
}

void _mutex::unlock()
{
	RUNTIME_THROW_TEST(pthread_mutex_unlock(&m_) == 0);
}

/**
 * If pthread_mutex_trylock() returns error and errno is different
 * then this method will thrown an exception.
 */
bool _mutex::trylock()
{
    if(pthread_mutex_trylock(&m_))
    {
        if(errno == EBUSY)
            return false;
        RUNTIME_THROW_FUN();
    }
    return true;
}


_mutexLock::_mutexLock(_mutex &m)
    : m_(&m)
{
    m_->lock();
}

_mutexLock::~_mutexLock()
{
    m_->unlock();
}


