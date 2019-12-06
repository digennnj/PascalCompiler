PROGRAM
var
integer stalactite:=0, normal1:=1, angus:=2, exitsign:=3, normal2:=4, falsealarm:=5, outside:=6;
string stal_desc := "A drop of water from a stalactite brushes your cheek. It stings a litte.";
string exit_desc := "A faint glow alerts you that the end is near at hand.";
string false_desc := "Curses! It was only a cave sprite.";
string angus_desc := "You hear the faint skirl of a bagpipe.";
string normal_desc := "Your footsteps resound from the cave walls.";
string sign := "Dare you enter the Maze of Doom?";
string giveup := "You heave a sign and turn back home. It probably wouldn't have been very fun anyway.";
string cavein := "With a sickening crunch the door slides down behind you. You are trapped.";
string wrongway := "You bump into a wall.";
string escape := "You blink the light from your eyes. How many centuries has it been since you've seen the sun? To your south there is a sign. You turn to read it: ";
integer you := outside, you_were;
character resp;
    procedure describe;
    BEGIN
        IF you = outside THEN write(sign);
        ELSE IF you = stalactite THEN write(stal_desc);
        ELSE IF you = angus THEN write(angus_desc);
        ELSE IF you = exitsign THEN write(exit_desc);
        ELSE IF you = falsealarm THEN write(false_desc);
        ELSE write(normal_desc);
    END;
BEGIN
    REPEAT BEGIN
        describe;

        you_were := you;
        read(resp);
        IF you = outside THEN BEGIN
            IF resp = 'y' THEN BEGIN
                write(cavein);
                you := stalactite;
            END
            ELSE write(giveup);
        END
        ELSE IF you = stalactite THEN BEGIN
            IF resp = 'n' THEN you := normal2;
            ELSE IF resp = 'e' THEN you := normal1;
            ELSE IF resp = 's' THEN write(wrongway);
            ELSE IF resp = 'w' THEN you := angus;
            ELSE write(wrongway);
        END
        ELSE IF you = normal1 THEN BEGIN
            IF resp = 'n' THEN you := exitsign;
            ELSE IF resp = 'e' THEN you := normal2;
            ELSE IF resp = 's' THEN write(wrongway);
            ELSE IF resp = 'w' THEN you := stalactite;
            ELSE write(wrongway);
        END
        ELSE IF you = angus THEN BEGIN
            IF resp = 'n' THEN write(wrongway);
            ELSE IF resp = 'e' THEN you := stalactite;
            ELSE IF resp = 's' THEN you := normal2;
            ELSE IF resp = 'w' THEN write(wrongway);
            ELSE write(wrongway);
        END
        ELSE IF you = exitsign THEN BEGIN
            IF resp = 'n' THEN you := falsealarm;
            ELSE IF resp = 'e' THEN BEGIN
                you := outside;
                write(escape);
            END
            ELSE IF resp = 's' THEN you := normal1;
            ELSE IF resp = 'w' THEN write(wrongway);
            ELSE write(wrongway);
        END
        ELSE IF you = normal2 THEN BEGIN
            IF resp = 'n' THEN you := angus;
            ELSE IF resp = 'e' THEN write(wrongway);
            ELSE IF resp = 's' THEN you := stalactite;
            ELSE IF resp = 'w' THEN you := normal1;
            ELSE write(wrongway);
        END
        ELSE IF you = falsealarm THEN BEGIN
            IF resp = 'n' THEN write(wrongway);
            ELSE IF resp = 'e' THEN write(wrongway);
            ELSE IF resp = 's' THEN you := exitsign;
            ELSE IF resp = 'w' THEN write(wrongway);
            ELSE write(wrongway);
        END
        ELSE write("how did you get in there?");
    END UNTIL you_were = outside AND resp = 'n';
END.
