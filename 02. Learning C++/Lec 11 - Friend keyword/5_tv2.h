/*
    If you see tv.h file, you will see that all the member functions of 
    Remote class call public functions of Tv class. In this way, they 
    don't need actually 'friend' status. The only member function of remote 
    class which needs 'friend' status is set_chan().
    
    The way to make Remote::set_chan() a friend to the Tv class is to 
    declare it as a friend in the Tv class declaration:
    
    class Tv
    {
        friend void Remote::set_chan(Tv & t, int c);
        ...
    };
    
    However, for the compiler to process this statement, it needs to have already 
    seen the Remote definition. Otherwise, it won’t know that Remote is a class and 
    that set_chan() is a method of that class.This suggests putting the Remote 
    definition above the Tv definition. This provides the following arrangement:
    
    class Tv;    // forward declaration
    class Remote { ... };
    class Tv { ... };
    
    Could we use the following arrangement?
    
    class Remote;   // forward declaration
    class Tv { ... };
    class Remote { ... };
    
    The answer is no.The reason, as mentioned earlier, is that when the 
    compiler sees that a Remote method is declared as a friend 
    in the Tv class declaration, the compiler needs to have already viewed 
    the declaration of the Remote class in general and of the set_chan() 
    method in particular.
    
    There is one more problem. In tv.h, the Remote declaration contains 
    inline code such as the following: 
    
    void onoff(Tv & t) { t.onoff(); }
    
    Because this calls a Tv method, the compiler needs to have seen the Tv class 
    declaration at this point so that it knows what methods Tv has. The solution 
    to this problem is to restrict Remote to method declarations and to place 
    the actual definitions after the Tv class. This leads to the following ordering:

    class Tv; // forward declaration
    class Remote { ... }; // Tv-using methods as prototypes only
    class Tv { ... };
    // put Remote method definitions here
*/

// REMOTE CLASSES USING A FRIEND MEMBER

#ifndef TVFM_H_
#define TVFM_H_
#include <iostream>

class Tv;

class Remote
{
    private:
        int mode;
    public:
        enum State {Off, On};
        enum {MinVal,MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        
        Remote(int m = TV) : mode(m) {}
        bool volup(Tv & t);    // prototype only
        bool voldown(Tv & t);
        void onoff(Tv & t) ;
        void chanup(Tv & t) ;
        void chandown(Tv & t) ;
        void set_mode(Tv & t) ;
        void set_input(Tv & t);
        void set_chan(Tv & t, int c);
};

class Tv
{
    public:
        friend void Remote::set_chan(Tv & t, int c);
        enum State{Off, On};
        enum {MinVal,MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
        void onoff() {state = (state == On)? Off : On;}
        bool ison() const {return state == On;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
        void set_input() {input = (input == TV)? DVD : TV;}
        void settings() const;
    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;
};

// Remote methods as inline functions
inline bool Remote::volup(Tv & t)   { return t.volup();}
inline bool Remote::voldown(Tv & t)  { return t.voldown();}
inline void Remote::onoff(Tv & t)   { t.onoff(); }
inline void Remote::chanup(Tv & t)   {t.chanup();}
inline void Remote::chandown(Tv & t)  {t.chandown();}
inline void Remote::set_mode(Tv & t)  {t.set_mode();}
inline void Remote::set_input(Tv & t)  {t.set_input();}
inline void Remote::set_chan(Tv & t, int c) {t.channel = c;}

// TV Method definitions
bool Tv :: volup ()
{
    if (volume < MaxVal)
    {
        volume++; 
        return true;
    }
    else 
        return false;
}

bool Tv :: voldown ()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv :: chanup ()
{
    if (channel < maxchannel)
        channel++;
    else 
        channel = 1;
}

void Tv :: chandown ()
{
    if (channel > 1)
        channel--;
    else 
        channel = maxchannel;
}

void Tv :: settings() const
{
    using std :: cout;
    using std :: endl;
    
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV? "TV" : "DVD") << endl;
    }
}
#endif
