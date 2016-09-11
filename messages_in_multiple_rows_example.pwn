/*
	Messages In Multiple Rows ~ Kevin-Reinke

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

// ** INCLUDES

#include <a_samp>
#include <zcmd>
#include <messages_in_multiple_rows>

// ** MAIN

main()
{
	print("Loaded \"messages_in_multiple_rows_example.amx\".");
}

// ** CALLBACKS

public OnGameModeInit()
{
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

// ** COMMANDS

CMD:msg1(playerid)
{
	new string[300];
	strcat(string, "The quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced by fox whelps. Bawds jog, flick quartz, vex nymphs. Waltz, bad nymph, for quick jigs vex! Fox nymphs grab quick-jived waltz. Brick quiz whangs jumpy veldt fox. Bright vixens jump; dozy fowl quack.");
	SendMessage(playerid, 0xFFF000FF, string);
	return 1;
}

CMD:msg2(playerid)
{
	new string[300];
	strcat(string, "The quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced by fox whelps. Bawds jog, flick quartz, vex nymphs. Waltz, bad nymph, for quick jigs vex! Fox nymphs grab quick-jived waltz. Brick quiz whangs jumpy veldt fox. Bright vixens jump; dozy fowl quack.");
	SendMessageToAll(0xFFF000FF, string);
	return 1;
}

CMD:msg3(playerid)
{
	new string[300];
	strcat(string, "The quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced by fox whelps. Bawds jog, flick quartz, vex nymphs. Waltz, bad nymph, for quick jigs vex! Fox nymphs grab quick-jived waltz. Brick quiz whangs jumpy veldt fox. Bright vixens jump; dozy fowl quack.");
	SendWhisperMessage(playerid, 0xFFF000FF, string, 10.0);
	return 1;
}

CMD:msg4(playerid)
{
	new string[300];
	strcat(string, "The quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced by fox whelps. Bawds jog, flick quartz, vex nymphs. Waltz, bad nymph, for quick jigs vex! Fox nymphs grab quick-jived waltz. Brick quiz whangs jumpy veldt fox. Bright vixens jump; dozy fowl quack.");
	SendPrivateMessage(playerid, 0xFFF000FF, string);
	return 1;
}

CMD:msg5(playerid)
{
	if(!IsPlayerAdmin(playerid))
	{
		SendClientMessage(playerid, 0xFF0000FF, "Note! {FFFFFF}You must use /rcon login <password> before using this command.");
	}
	else
	{
		new string[300];
		strcat(string, "The quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced by fox whelps. Bawds jog, flick quartz, vex nymphs. Waltz, bad nymph, for quick jigs vex! Fox nymphs grab quick-jived waltz. Brick quiz whangs jumpy veldt fox. Bright vixens jump; dozy fowl quack.");
		SendMessageToRCONAdmins(0xFFF000FF, string);
	}
	return 1;
}