#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  try
  {
    std::ofstream outfile(filename);
    num_channels == 1 ? outfile << "P2" << std::endl : outfile << "P3" << std::endl;
    outfile << width << " " << height << std::endl;
    outfile << 255 << std::endl;
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        static unsigned char color[3];
        color[0] = data[0 + num_channels * (j + width * i)]; /* red */
        outfile << static_cast<unsigned>(color[0]) << " ";

        if (num_channels == 3)
        {
          color[1] = data[1 + num_channels * (j + width * i)]; /* green */
          color[2] = data[2 + num_channels * (j + width * i)]; /* blue */
          outfile << static_cast<unsigned>(color[1]) << " ";
          outfile << static_cast<unsigned>(color[2]) << std::endl;
        }
        else
        {
          outfile << std::endl;
        }
      }
    }
    outfile.close();
    return true;
  }
  // Catch any errors
  catch (...)
  {
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}
