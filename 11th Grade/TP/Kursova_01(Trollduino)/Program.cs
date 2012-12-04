using System;
using System.IO.Ports;

namespace RoboControl
{
    class Program
    {
        static void Main(string[] args)
        {
            SerialPort device = new SerialPort("COM8", 9600);
            device.Open();
            while (true)
            {
                string command = "0";
                try
                {
                    switch (Console.ReadKey().Key)
                    {
                        case ConsoleKey.LeftArrow:
                            {
                                command = "4";
                                break;
                            }

                        case ConsoleKey.RightArrow:
                            {
                                command = "3";

                                break;
                            }

                        case ConsoleKey.UpArrow:
                            {
                                command = "1";

                                break;
                            }

                        case ConsoleKey.DownArrow:
                            {
                                command = "2";
                                break;
                            }

                        default:
                            {
                                command = "0";
                                break;

                            }
                    }
                }
                catch (Exception ex)
                {
                    break;
                }
                device.Write(command);
                char[] buffer = {'a'};
                device.Read(buffer, 0, 1);
                Console.WriteLine(buffer);
            }
            device.Close();
        }
    }
}
