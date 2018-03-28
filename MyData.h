/*
  The MIT License (MIT)

  Copyright © 2018 Sven Agneessens <sven.agneessens@gmail.com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef MYDATA_H_
#define MYDATA_H_

#include <Arduino.h>

#define SIZE_LAT_LON 1440 // 24h * 60min

struct LatLon {
  int32_t _latitude;
  int32_t _longitude;
};

struct MyData {
  uint16_t _header;

  uint16_t _amount;
  uint8_t _power;
  struct LatLon _loc[SIZE_LAT_LON];

  uint16_t _crc16;

public:
  void read();
  void commit(bool forced = false);
  void reset();

  uint16_t getNumberOfMeasurements() const { return _amount; }
  uint8_t getPower() const { return _power; }

  void setPower(uint8_t power);
  bool addLocation(int32_t lat, int32_t lon);
};

extern MyData myData;

#endif /* MYDATA_H_ */
