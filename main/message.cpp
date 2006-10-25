/***************************************************************************
 *   Copyright (C) 2005/06 by The Quassel Team                             *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "message.h"
#include <QDataStream>

QDataStream &operator<<(QDataStream &out, const Message &msg) {
  out << (quint8)msg.type << (quint8)msg.flags << msg.sender << msg.msg << (quint32)msg.timeStamp.toTime_t();
  return out;
}

QDataStream &operator>>(QDataStream &in, Message &msg) {
  quint8 t, f;
  quint32 ts;
  in >> t >> f >> msg.sender >> msg.msg >> ts;
  msg.type = (Message::Type)t;
  msg.flags = (Message::Flags)f;
  msg.timeStamp = QDateTime::fromTime_t(ts);
  return in;
}
