// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2009, Roboterclub Aachen e.V.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * $Id: default_postman.hpp 77 2009-10-15 18:34:29Z thundernail $
 */
// ----------------------------------------------------------------------------

#ifndef	XPCC_DEFAULT_POSTMAN_HPP
#define	XPCC_DEFAULT_POSTMAN_HPP

/**
 * @defgroup 	communication Communication
 * @brief 		Default Postman can be used if no other more efficient
 * 				Postman is avalible.
 *
 * DESC DESC
 *
 * @version		$Id: default_postman.hpp 77 2009-10-15 18:34:29Z thundernail $
 */

#include "postman.hpp"

namespace xpcc
{
	class DefaultPostman:Postman
	{
	public:
		DefaultPostman(int eventlist, int componentlist);
		
		~DefaultPostman();
		
		virtual DeliverInfo
		deliverPacket(const BackendInterface& interface);
		
		virtual DeliverInfo
		deliverPacket(const Header &header, SmartPayload& payload);
				
		virtual DeliverInfo
		deliverPacket(const Header &header);
		
	private:
		// the lists
	};
}



#endif	// XPCC_DEFAULT_POSTMAN_HPP
