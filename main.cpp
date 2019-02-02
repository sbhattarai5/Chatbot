#include <iostream>
#include <cstring>

void greeting(char name[])
{
  std::cout << "<< What's your First name?\n<< ";
  std::cin.getline(name, 100);
  std::cout << "<< Hey " << name << '!' << " How can I help you?" << '\n';
}


int main()
{
  
  bool gone_bar = false;  
  bool talked_security = false;
  bool talked_bartender = false;
  bool talked_alexa = false;
  bool age_checked = false;
  bool is_home = true;
  
  int age;
  char name[100];
  char c[100];
  greeting(name);
  
  while(1)
  {
    std::cout << "<< ";
    std::cin.getline(c, 100);
    if (!strncmp(c, "exit", 100))
    {
        break;
    } 
    else if (strnlen(c, 100) > 0)
    {
        std::cout << "<< ";
        
        if (!strncmp(c, "Go to the Bar", 100))
        {
            if (!gone_bar)
            {
                std::cout << "You might wanna 'Talk to the Security' to get in.\n";
                gone_bar = true;
                is_home = false;
            }
            else
            {
                std::cout << "Did you just forget that you are in a bar?\n";
            }
            continue;
        }
        else if (!strncmp(c, "Talk to the Security", 100))
        {
            if (gone_bar)
            {
                if (!age_checked)
                {
                    std::cout << "What is your age?\n<< ";
                    std::cin.getline(c, 4);
                    age = strtol(c, NULL, 10);
                    age_checked = true;
                    std::cout << "<< ";
                }
                if (age < 21)
                {
                    
                    std::cout << "Come after " << 21 - age << " years! 'Go to the Home' for now.\n";
                    continue;
                }
                else
                {
                    talked_security = true;
                    std::cout << "Welcome to the Bar! Go and 'Talk to the Bartender'.\n";
                    continue;
                }
                
            }
            else
            {
                std::cout << "'Go to the Bar' to talk with security, Son!\n";
                continue;
            }
            
        }
        else if (!strncmp(c, "Go to the Home", 100))
        {
            if (!is_home)
            {
                gone_bar = false;
                is_home = true;
                talked_security = false;
                age_checked = false;
                talked_bartender = false;
                talked_alexa = false;
                std::cout << "You are home! Now what?\n";
            }
            else
            {
                std::cout << "Is there a home inside a home? 'Go to the Bar' instead of being a psycho at home.\n";
            }
            
        }
        else if (!strncmp(c, "Talk to the Bartender", 100))
        {
            if (talked_security and talked_alexa)
            {
                std::cout << "Red wine for Alexa, Have fun.\n";
                talked_bartender = true;
            }
            else if (talked_security)
            {
                std::cout << "Here's your Perfect Vodka Martini. 'Talk to Alexa', she is sitting next to you.\n";
                talked_bartender = true;
            }
            else if (gone_bar)
            {
                std::cout << "Come in, first! Clue: 'Talk to the Security\n";
            }
            else
            {
                std::cout << "Bartender is not omnipotenet. 'Go to the Bar' to talk\n";
            }
        }
        else if (!strncmp(c, "Talk to Alexa", 100))
        {
            if (talked_security)
            {
                std::cout << "Hey Honey. I would like you if you 'Talk the Bartender' and order me a red wine? ;-)\n";
                talked_alexa = true;
            }
            else if (gone_bar)
            {
                std::cout << "Come in, first! Clue: 'Talk to the Security\n";
            }
            else
            {
                std::cout << "Alexa in in bar. 'Go to the Bar' to talk\n";
            }
        }
        else
        {
            std::cout << "You seem lost. 'Go to the Bar' and have fun\n";
            continue;
        }
    }
  } 

    return 0;
}

