/*
    Suppose you must program a simple simulation of a television and a 
    remote control. You decide to define a Tv class representing a television 
    and a Remote class representing a remote control. Clearly, there should be 
    some sort of relationship between these classes, but of what kind? 
    
    A remote control is not a television and vice versa, so the 'is-a' 
    relationship of public inheritance doesn’t apply. Nor anything either is a 
    component of the other, so the 'has-a' relationship of containment doesn’t 
    apply.
    
    What is true is that a remote control can modify the state of a television, 
    and this suggests making the Remote class a friend to the Tv class.
*/

#ifndef TV_H_
#define TV_H_

class Tv
{
    private:
        int state; // on or off
        int volume; // assumed to be digitized
        int maxchannel; // maximum number of channels
        int channel; // current channel setting
        int mode; // broadcast or cable
        int input; // TV or DVD
    public:
        //Remote is friend class which can acess private members of TV class
        friend class Remote;  
        enum {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        
        Tv (int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
        
        void onoff()  { state = (state == On) ? Off : On; }
        bool ison() const {return state == On; }
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode()  {mode = (mode == Antenna)? Cable : Antenna;}
        void set_input()  {input = (input == TV)? DVD : TV;}
        void settings() const; // display all settings
};

class Remote
{
    private:
        int mode;  //Controls TV or DVD
    public:
        Remote(int m = Tv::TV) : mode(m) {}
        bool volup(Tv & t)   { return t.volup();}
        bool voldown(Tv & t)   { return t.voldown();}
        void onoff(Tv & t)   { t.onoff(); }
        void chanup(Tv & t)   {t.chanup();}
        void chandown(Tv & t)   {t.chandown();}
        void set_chan(Tv & t, int c)  {t.channel = c;}
        void set_mode(Tv & t)   {t.set_mode();}
        void set_input(Tv & t)   {t.set_input();}
};

#endif
