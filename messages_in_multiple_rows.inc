/*
	Messagese In Multiple Rows ~ Kevin-Reinke

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _mimr_included
	#endinput
#endif

#define _mimr_included

#if !defined MAX_MESSAGE_LENGTH
	#define MAX_MESSAGE_LENGTH 100
#endif

#if !defined strcpy
	#define strcpy(%0,%1,%2) strcat((%0[0] = '\0', %0), %1, %2)
#endif

// ** FUNCTIONS

// *** GENERAL

stock SendMessage(playerid, color, message[], length_1 = MAX_MESSAGE_LENGTH)
{
	new length_2 = strlen(message);
	if(length_2 <= length_1)
	{
		SendClientMessage(playerid, color, message);
	}
	else
	{
		new string[144], last_space, escape = floatround(length_1 / 1.2);
		while(length_2 > length_1)
		{
			strcpy(string, message, 144);

			for(new i = 0; i <= length_2; i ++)
			{
				if(message[i] == ' ' && i <= length_1)
				{
					last_space = i;
				}

				if(i > length_1)
				{
					i = length_2;
				}
			}

			if(!last_space)
			{
				strdel(string, length_1, strlen(string));
				strdel(message, 0, length_1);

				length_2 -= length_1;
			}
			else if(last_space < escape)
			{
				strdel(string, escape, strlen(string));
				strdel(message, 0, escape);

				length_2 -= escape;
				last_space = 0;
			}
			else 
			{
				strdel(string, last_space, strlen(string));
				strdel(message, 0, (last_space + 1));

				length_2 -= last_space;
				last_space = 0;
			}

			SendClientMessage(playerid, color, string);

			if(length_2 < length_1)
			{
				SendClientMessage(playerid, color, message);
			}
		}
	}
	return 1;
}

stock SendMessageToAll(color, message[], length_1 = MAX_MESSAGE_LENGTH)
{
	new length_2 = strlen(message);
	if(length_2 <= length_1)
	{
		SendClientMessageToAll(color, message);
	}
	else
	{
		new string[144], last_space, escape = floatround(length_1 / 1.2);
		while(length_2 > length_1)
		{
			strcpy(string, message, 144);

			for(new i = 0; i <= length_2; i ++)
			{
				if(message[i] == ' ' && i <= length_1)
				{
					last_space = i;
				}

				if(i > length_1)
				{
					i = length_2;
				}
			}

			if(!last_space)
			{
				strdel(string, length_1, strlen(string));
				strdel(message, 0, length_1);

				length_2 -= length_1;
			}
			else if(last_space < escape)
			{
				strdel(string, escape, strlen(string));
				strdel(message, 0, escape);

				length_2 -= escape;
				last_space = 0;
			}
			else 
			{
				strdel(string, last_space, strlen(string));
				strdel(message, 0, (last_space + 1));

				length_2 -= last_space;
				last_space = 0;
			}

			SendClientMessageToAll(color, string);

			if(length_2 < length_1)
			{
				SendClientMessageToAll(color, message);
			}
		}
	}
	return 1;
}

stock SendWhisperMessage(playerid, color, message[], Float:range, length_1 = MAX_MESSAGE_LENGTH)
{
	new length_2 = strlen(message);
	if(length_2 <= length_1)
	{
		for(new i = 0, j = GetPlayerPoolSize(); i <= j; i ++)
		{
			if(!IsPlayerConnected(i) && !IsPlayerCloseToPlayer(i, playerid, range))
			{
				continue;
			}

			SendClientMessage(i, color, message);
		}
	}
	else
	{
		new string[144], last_space, escape = floatround(length_1 / 1.2);
		while(length_2 > length_1)
		{
			strcpy(string, message, 144);

			for(new i = 0; i <= length_2; i ++)
			{
				if(message[i] == ' ' && i <= length_1)
				{
					last_space = i;
				}

				if(i > length_1)
				{
					i = length_2;
				}
			}

			if(!last_space)
			{
				strdel(string, length_1, strlen(string));
				strdel(message, 0, length_1);

				length_2 -= length_1;
			}
			else if(last_space < escape)
			{
				strdel(string, escape, strlen(string));
				strdel(message, 0, escape);

				length_2 -= escape;
				last_space = 0;
			}
			else 
			{
				strdel(string, last_space, strlen(string));
				strdel(message, 0, (last_space + 1));

				length_2 -= last_space;
				last_space = 0;
			}

			for(new i = 0, j = GetPlayerPoolSize(); i <= j; i ++)
			{
				if(!IsPlayerConnected(i) && !IsPlayerCloseToPlayer(i, playerid, range))
				{
					continue;
				}
				
				SendClientMessage(i, color, string);

				if(length_2 < length_1)
				{
					SendClientMessage(i, color, message);
				}
			}
		}
	}
	return 1;
}

stock SendPrivateMessage(for_playerid, color, message[], length = MAX_MESSAGE_LENGTH)
{
	return SendMessage(for_playerid, color, message, length);
}

stock SendMessageToRCONAdmins(color, message[], length_1 = MAX_MESSAGE_LENGTH)
{
	new length_2 = strlen(message);
	if(length_2 <= length_1)
	{
		for(new i = 0, j = GetPlayerPoolSize(); i <= j; i ++)
		{
			if(!IsPlayerAdmin(i))
			{
				continue;
			}

			SendClientMessage(i, color, message);
		}
	}
	else
	{
		new string[144], last_space, escape = floatround(length_1 / 1.2);
		while(length_2 > length_1)
		{
			strcpy(string, message, 144);

			for(new i = 0; i <= length_2; i ++)
			{
				if(message[i] == ' ' && i <= length_1)
				{
					last_space = i;
				}

				if(i > length_1)
				{
					i = length_2;
				}
			}

			if(!last_space)
			{
				strdel(string, length_1, strlen(string));
				strdel(message, 0, length_1);

				length_2 -= length_1;
			}
			else if(last_space < escape)
			{
				strdel(string, escape, strlen(string));
				strdel(message, 0, escape);

				length_2 -= escape;
				last_space = 0;
			}
			else 
			{
				strdel(string, last_space, strlen(string));
				strdel(message, 0, (last_space + 1));

				length_2 -= last_space;
				last_space = 0;
			}

			for(new i = 0, j = GetPlayerPoolSize(); i <= j; i ++)
			{
				if(!IsPlayerAdmin(i))
				{
					continue;
				}
				
				SendClientMessage(i, color, string);

				if(length_2 < length_1)
				{
					SendClientMessage(i, color, message);
				}
			}
		}
	}
	return 1;
}

// *** OTHER

stock IsPlayerCloseToPlayer(player_to_check, player_to_compare, Float:range)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(player_to_compare, x, y, z);

	if(IsPlayerInRangeOfPoint(player_to_check, range, x, y, z) && GetPlayerInterior(player_to_check) == GetPlayerInterior(player_to_compare) && GetPlayerVirtualWorld(player_to_check) == GetPlayerVirtualWorld(player_to_compare) && GetPlayerState(player_to_check) != PLAYER_STATE_SPECTATING && GetPlayerState(player_to_compare) != PLAYER_STATE_SPECTATING)
	{
		return 1;
	}
	return 0;
}