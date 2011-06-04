//
//  SourceText.cpp
//  CircleText
//
//  Created by fabiantheblind on 02.06.11.
//  Copyright 2011 the-moron.productions. All rights reserved.
//

#include "SourceText.h"


//--------------------------------------------------------------
// this is a helper function to genrate some text with lots of linebreaks
// solo it works



//int main () {
//    
//    
//	string s;
//	s = loadPlaceHolderText();
//    cout << s << endl;
//    
//    
//    return 0;
//}


string loadPlaceHolderText(){
    std::string s;
    std::string line;
    std::ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
		while (! myfile.eof() )
		{
            getline (myfile,line);
            line = breakText(line);
            
            s = s +line;
		}
		myfile.close();
       	
        return s; 
    } else{
        
        std::cout << "Unable to open file";
        
        std::string mess = "this is fabiantheblind Keeper of the Sacred Chao\n Adept of Canhoto son of H.Z. and Dr.D member of the moron net \\nwho travells the hello worlds and does stuff that involves things\n";
        return mess + mess+ mess+ mess+ mess+ mess+ mess+ mess+ mess+ mess+ mess+ mess+ mess+ mess;
	}
    
}


string breakText(string s){
	
    replace(s.begin(), s.end(), ',', '\n');
	return s;
}




std::string placeholder(){


    std::string res = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam non odio id velit sagittis tincidunt eu quis leo. Fusce varius faucibus porta. Mauris in eros lorem. Suspendisse potenti. Mauris sed nulla non sem rutrum porttitor. Praesent pellentesque urna quis erat porttitor vitae ornare velit suscipit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Pellentesque porttitor adipiscing mi, sed hendrerit leo dignissim at. In hac habitasse platea dictumst. Morbi elit ipsum, pulvinar nec cursus vitae, tristique sit amet felis. Fusce varius mauris metus. Cras ut odio dolor. Mauris faucibus, dui non mollis lacinia, lorem urna ornare dolor, sagittis euismod tortor tellus eget erat. Aliquam eleifend fringilla faucibus. Suspendisse lobortis lectus eget nibh sollicitudin tristique. Donec suscipit egestas urna eu tempus. Proin mi urna, sodales vitae volutpat non, vestibulum quis libero. Curabitur ipsum neque, sollicitudin nec mattis quis, dignissim et quam. Pellentesque non elit massa. Nulla at ipsum mauris.\nAenean luctus tempor libero sed facilisis. Donec luctus nisl in orci mollis sed posuere libero sagittis. Phasellus tristique accumsan tincidunt. Phasellus at nunc ultrices est interdum elementum non non velit. Praesent suscipit tempor lacinia. Maecenas suscipit leo a mi placerat tincidunt. Sed eget magna ipsum, vel malesuada ante. Aenean porttitor iaculis convallis. Sed vitae imperdiet ipsum. Ut vulputate condimentum libero vitae tristique.\nProin vel auctor mauris. Donec malesuada ultrices diam. Vestibulum eleifend pellentesque nibh, et malesuada enim egestas in. Morbi convallis luctus porta. Fusce sed augue in lectus lobortis aliquam. Aliquam erat volutpat. Morbi leo eros, dignissim eget gravida vel, dapibus sed augue. Aliquam odio nulla, sollicitudin non tincidunt interdum, venenatis nec sem. Etiam bibendum gravida orci, ut aliquam leo ornare quis. Nulla facilisi. Nullam at dui orci, quis molestie nulla. Nam ac blandit diam. Etiam eget faucibus purus. Vivamus bibendum nibh et lectus malesuada vel feugiat sapien porttitor. Sed lacus urna, scelerisque vel aliquam nec, sodales eget mauris.\nClass aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Pellentesque aliquam libero et erat ullamcorper at fringilla dui cursus. Cras arcu elit, fermentum eget laoreet et, rhoncus faucibus turpis. Phasellus quis urna et purus faucibus tincidunt vitae non arcu. Duis eu diam leo, eget fermentum neque. In consectetur pharetra nibh semper rutrum. Vivamus ac massa sit amet risus condimentum ornare ut vitae nisi. Donec a lacus sed leo mattis convallis ut ut nisl. Etiam volutpat, nisl nec vestibulum auctor, sem neque venenatis odio, quis ornare diam felis ac ante. Curabitur tempus scelerisque massa dictum congue. Quisque purus quam, scelerisque vitae eleifend mollis, blandit eget justo. In nunc erat, vehicula quis luctus in, tincidunt id mauris. Mauris blandit, ipsum et accumsan porttitor, risus lectus ultrices leo, nec rutrum arcu lorem eget turpis.\nNullam molestie ultricies dolor, vitae sodales erat fringilla eu. Sed condimentum orci sed enim facilisis nec malesuada metus rutrum. Fusce placerat, massa a tincidunt auctor, nisl arcu pretium ligula, sed pellentesque enim orci ut dolor. Ut venenatis sem id nulla malesuada non varius justo varius. Vestibulum pharetra faucibus ornare. Pellentesque ultricies lobortis nisl sed pulvinar. Nunc pellentesque, felis in egestas consectetur, metus risus lacinia elit, vel lobortis erat orci sit amet urna. In sapien justo, porttitor eget sagittis vel, convallis eget erat. Vestibulum eu leo arcu. Praesent sit amet orci sit amet orci rhoncus pretium nec sit amet ipsum.\nInteger lobortis est nec nulla laoreet bibendum. Phasellus aliquam neque sit amet lorem lacinia in molestie metus bibendum. Integer faucibus nisi urna. Nullam pretium dignissim neque quis auctor. In lobortis porta rhoncus. Suspendisse est quam, euismod eget mattis et, congue ut purus. Sed non elementum arcu. Duis diam est, lacinia ut suscipit quis, condimentum sit amet sapien. Duis id risus velit, at scelerisque nisl. Donec varius aliquam posuere. Mauris tristique eros vel sapien condimentum et commodo leo pharetra. Phasellus porttitor pharetra gravida.\nMorbi interdum sapien in nisi congue blandit. Aliquam dui elit, lobortis eget auctor eu, semper ac odio. Donec neque neque, aliquam ac fermentum sit amet, fermentum eu velit. Suspendisse ut purus diam. Phasellus vitae lobortis augue. Sed id nunc erat, quis bibendum felis. Donec feugiat lectus et eros tincidunt rhoncus. Pellentesque leo ipsum, consectetur eu malesuada rutrum, pretium eget nunc. Vestibulum justo dui, semper ac hendrerit in, dapibus et magna. Morbi laoreet libero non nunc hendrerit tristique. Nullam nec massa pellentesque nibh congue ornare. Cras viverra risus suscipit ante placerat sed tristique augue pretium. Nunc blandit gravida nunc quis laoreet. Vestibulum pulvinar lobortis facilisis.\nPellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Sed et lacus lorem. Donec lectus libero, rutrum vitae laoreet facilisis, convallis sed ante. Praesent elit lorem, ornare id vehicula a, gravida eu turpis. Etiam justo orci, tincidunt eget rutrum sed, hendrerit sit amet dolor. Suspendisse iaculis luctus erat at accumsan. Sed ullamcorper, neque vitae luctus vehicula, eros velit posuere ligula, a accumsan ipsum est in turpis. Vestibulum sapien erat, dignissim at volutpat sed, consequat id ipsum. Sed vitae sapien nec purus fringilla posuere nec volutpat odio. Quisque risus erat, pulvinar eget condimentum dignissim, posuere ut ligula. Proin sit amet dolor sem, et malesuada felis. Maecenas ultrices auctor consequat. Vivamus quis sapien justo, ac pellentesque dui.";

}