#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<unordered_map>
using namespace sf;
using namespace std;
int main() {
	//making a simple sfml window
	RenderWindow window(VideoMode(976, 336), "My Piano");
	//making texture of the piano 
	Texture textureofPiano;
	if (!textureofPiano.loadFromFile("pianoLayout.jpg"))
	{
		return EXIT_FAILURE;
	}
	//making sprite for the piano
	Sprite pianosprite(textureofPiano);
	IntRect posOFblackkeys[]{
		IntRect(22,111,22,142),//Key1-3a#-f1
		IntRect(61,111,22,142),//Key2-3c#-f2
		IntRect(101,111,22,142),//Key3-3d#-f3
		IntRect(161,111,22,142),//Key4-3f#-f4
		IntRect(200,111,22,142),//Key5-3g#-f5
		IntRect(239,111,22,142),//Key6-4a#-f6
		IntRect(300,111,22,142),//Key7-4c#-f7
		IntRect(338,111,22,142),//Key8-4d#-f8
		IntRect(378,111,22,142),//Key9-4f#-f9
		IntRect(438,111,22,142),//Key10-4g#-f10
		IntRect(477,111,22,142),//Key11-5a#-1
		IntRect(518,111,22,142),//Key12-5c#-2
		IntRect(576,111,22,142),//Key13-5d#-3
		IntRect(616,111,22,142),//Key14-5f#-4
		IntRect(655,111,22,142),//Key15-5g#-5
		IntRect(714,111,22,142),//Key16-6a#-6
		IntRect(754,111,22,142),//Key17-6b#-7
		IntRect(793,111,22,142),//Key18-6c#-8
		IntRect(853,111,22,142),//Key19-6f#-9
		IntRect(898,111,22,142),//Key20-6g#-0
		IntRect(932,111,22,142)//Key21-7a#-
	};
	IntRect PosOfWhitekeys[]{
		IntRect{4,253,32,72},//key1-3a-q
		IntRect{38,253,32,72},//key2-3b-w
		IntRect{72,253,32,72},//key3-3c-e
		IntRect{107,253,32,72},//key4-3d-r
		IntRect{143,253,32,72},//key5-3e-t
		IntRect{178,253,32,72},//key6-3f-y
		IntRect{212,253,32,72},//key7-3g-u
		IntRect{246,253,32,72},//key8-4a-i
		IntRect{282,253,32,72},//key9-4b-o
		IntRect{315,253,32,72},//key10-4c-p
		IntRect{350,253,32,72},//key11-4d-a
		IntRect{383,253,32,72},//key12-4e-s
		IntRect{421,253,32,72},//key13-4f-d
		IntRect{455,253,32,72},//key14-4g-f
		IntRect{489,253,32,72},//key15-5a-g
		IntRect{524,253,32,72},//key16-5b-h
		IntRect{559,253,32,72},//key17-5c-j
		IntRect{593,253,32,72},//key18-5d-k
		IntRect{627,253,32,72},//key19-5e-l
		IntRect{661,253,32,72},//key20-5f-z
		IntRect{697,253,32,72},//key21-5g-x
		IntRect{731,253,32,72},//key22-6a-c
		IntRect{766,253,32,72},//key23-6b-v
		IntRect{800,253,32,72},//key24-6c-b
		IntRect{836,253,32,72},//key25-6d-n
		IntRect{870,253,32,72},//key26-6e-m
		IntRect{904,253,32,72},//key27-6f-<
		IntRect{939,253,32,72}//key28-6g->
	};
	//loading audio data for all white keys.
	string fpath = "blackKeynotes/";
	char notealpha = 'a';
	int notenum = 3;
	int WarrI = 0;
	SoundBuffer audioForWhitekey[29];
	for (int n = 3; n <= 6; n++)
	{
		for (int a = 0; a < 7; a++)
		{
			if (!audioForWhitekey[WarrI].loadFromFile(to_string(n) + "-" + string(1, notealpha) + ".wav"))
			{ 
				return EXIT_FAILURE;
			}
			WarrI++;
			notealpha++;
		}
		notealpha = 'a';
	}
	//loading audio data for black keys
	SoundBuffer audioForBlackkey[21];
	int BarrI = 0;
	for (int i = 3; i <= 6; i++)
	{
		if (!audioForBlackkey[BarrI].loadFromFile(to_string(i) + "-a#.wav"))
		{
			return EXIT_FAILURE;
		}
		BarrI++;
		if (!audioForBlackkey[BarrI].loadFromFile(to_string(i) +"-c#.wav"))
		{
			return EXIT_FAILURE;
		}
		BarrI++;
		if (!audioForBlackkey[BarrI].loadFromFile(to_string(i) +"-d#.wav"))
		{
			return EXIT_FAILURE;
		}
		BarrI++;
		if (!audioForBlackkey[BarrI].loadFromFile(to_string(i) +"-f#.wav"))
		{
			return EXIT_FAILURE;
		}
		BarrI++;
		if (!audioForBlackkey[BarrI].loadFromFile(to_string(i) +"-g#.wav"))
		{
			return EXIT_FAILURE;
		}
		BarrI++;
	}
	// setting up sounds for white keys
	Sound soundForwhite[28];
	for (int i = 0; i < 28; i++)
	{
		soundForwhite[i].setBuffer(audioForWhitekey[i]);
	}
	// setting up sounds for black keys
	Sound soundForblack[21];
	for (int i = 0; i < 21; i++)
	{
		soundForblack[i].setBuffer(audioForBlackkey[i]);
	}
		unordered_map<Keyboard::Key, int> blackKeyMappings = {
		{Keyboard::F1, 0}, {Keyboard::F2, 1}, {Keyboard::F3, 2}, {Keyboard::F4, 3},
		{Keyboard::F5, 4}, {Keyboard::F6, 5}, {Keyboard::F7, 6}, {Keyboard::F8, 7},
		{Keyboard::F9, 8}, {Keyboard::F10, 9}, {Keyboard::Num1, 10}, {Keyboard::Num2, 11},
		{Keyboard::Num3, 12}, {Keyboard::Num4, 13}, {Keyboard::Num5, 14}, {Keyboard::Num6, 15},     
		{Keyboard::Num7, 16}, {Keyboard::Num8, 17}, {Keyboard::Num9, 18}, {Keyboard::Num0, 19},
		{Keyboard::Hyphen, 20}
	};

		unordered_map<Keyboard::Key, int> whiteKeyMappings = {
		{Keyboard::Q, 0}, {Keyboard::W, 1}, {Keyboard::E, 2}, {Keyboard::R, 3},
		{Keyboard::T, 4}, {Keyboard::Y, 5}, {Keyboard::U, 6}, {Keyboard::I, 7},
		{Keyboard::O, 8}, {Keyboard::P, 9}, {Keyboard::A, 10}, {Keyboard::S, 11},
		{Keyboard::D, 12}, {Keyboard::F, 13}, {Keyboard::G, 14}, {Keyboard::H, 15},
		{Keyboard::J, 16}, {Keyboard::K, 17}, {Keyboard::L, 18}, {Keyboard::Z, 19},
		{Keyboard::X, 20}, {Keyboard::C, 21}, {Keyboard::V, 22}, {Keyboard::B, 23},
		{Keyboard::N, 24},{Keyboard::M, 25}, {Keyboard::Comma, 26}, {Keyboard::Period, 27}
	};
	//main loop for event and inputs handeling 
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			//mouse click event handling 
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Vector2i mousePos = Mouse::getPosition(window);
					//playing sounds on mouse click on white buttons
					for (int i = 0; i < 28; i++)
					{
						if (PosOfWhitekeys[i].contains(mousePos))
						{
							soundForwhite[i].play();
						}
					}
					//playing sound for black keys
					for (int i = 0; i < 21; i++)
					{
						if (posOFblackkeys[i].contains(mousePos))
						{
							soundForblack[i].play();
						}
					}
				}
			}

			//checking inputs for keyboard;
			if (event.type == Event::KeyPressed)
			{
				auto blackKeyIndex = blackKeyMappings.find(event.key.code);
				if (blackKeyIndex != blackKeyMappings.end()) {
					// Play the sound corresponding to the black key
					soundForblack[blackKeyIndex->second].play();
				}
				else {
					// Check if the pressed key is a white key
					auto whiteKeyIndex = whiteKeyMappings.find(event.key.code);
					if (whiteKeyIndex != whiteKeyMappings.end()) {
						// Play the sound corresponding to the white key
						soundForwhite[whiteKeyIndex->second].play();
					}
				}
			}
		}
		window.clear();
		window.draw(pianosprite);
		window.display();
	}
	return 0;
}