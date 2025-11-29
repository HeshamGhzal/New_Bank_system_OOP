#include <iostream>
#include "USER/clsBank_user.h"

int main(){
    auto u = clsbank_user::find_user("user1", "1234");
    if (u.is_empty()){
        std::cout << "find_user returned empty for user1/1234" << std::endl;
    } else {
        std::cout << "Found user: " << u.get_user_name() << " with password: " << u.get_Password() << "\n";
    }
    return 0;
}
