enum state
{
    OFF=0,
    ON
} ;

enum Tlights
{
    G=0,
    O,
    R,
    g,
    o,
    r
} ;
struct vcs
{
    char VehicleState;
    char speed;
    char ACState;
    char EnginTempC;
} ;

struct Sensors
{
    char TLC ;
    char RT;
    char ET;
} ;

void VCS (struct Sensors *s,struct vcs *v);
