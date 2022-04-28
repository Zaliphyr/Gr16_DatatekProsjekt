#pragma once
#define cc_h

class cc
{
    public:
        unsigned int low_buffer = 600;
        unsigned int high_buffer = 800;

        String mode = "auto";
        String cc_state = "following_line";
        int want = 10;
        /* job items:
            getting_post: Going to post office and picking up post
            delivering_post: Going to houses to deliver post
        */        
        String job = "getting_post";
        // If true then stops at chrger to charge
        bool need_charge = false;

        // linefollower variables
        int pos;
        unsigned int linesensorValues[5];
        int error;
        int lastError = 0;
        float Kp = 0.6;
        float Td = 2;

        // intersection variables
        /*  Intersection types:
            0: No intersection
            1: Left intersection
            2: Right intersection
            3: Left and right intersection
        */
        int intersection_type = 0;
        /*  Intersection straight:
            0: No straight
            1: Straight
        */
        int intersection_straight = 0;
        int intersection_number = 0;

        int repeat = 0;
        int step = 0;
        

        int encoder_turn_count = 0;

        long unsigned int lost_line_time = 0;
        long unsigned int wait_at_place = 0;

        // Public functions
        void init();
        void loop();

    private:
        // Private functions
        void intersection_checker();
        void calibratin();
        void lost_line();
        void followLine();
        void turn_sharp(bool left);
        void turn_off();

        void state_follow_line();
        void state_intersection();
        void state_lost_line();
        void state_getting_post();
        void state_delivering_post();
        void state_going_to_charger();
        
        void update_intersection_number();
};
