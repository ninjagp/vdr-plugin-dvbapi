/*
 *  vdr-plugin-dvbapi - softcam dvbapi plugin for VDR
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ___CAPMT_H
#define ___CAPMT_H

#include <linux/dvb/ca.h>
#include <vdr/dvbdevice.h>
#include <vdr/thread.h>
#define DMX_FILTER_SIZE 16
#define TIMEOUT 800  // ms

class CAPMT
{
private:
  int read_t(int fd, unsigned char *buffer);
  int set_filter_pmt(int fd, int pid);
  int set_filter(int fd, int pid);
  int get_pmt_pid(unsigned char *buffer, int SID);
  bool get_pmt(const int adapter, const int sid, unsigned char *buffer);

public:
  int send(const int adapter, const int sid, int socket_fd, const unsigned char *vdr_caPMT, int vdr_caPMTLen);
};

#endif // ___CAPMT_H
