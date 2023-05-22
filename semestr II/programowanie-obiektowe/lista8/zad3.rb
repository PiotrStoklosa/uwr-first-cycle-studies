#Piotr Stoklosa zad3
class Jawna

    def initialize(napis_jawny)
        @napis_jawny = napis_jawny
    end

    def zaszyfruj(klucz)

	wynik = ""
	range = @napis_jawny.length

        for i in 1..range do
            wynik += klucz[@napis_jawny[i-1]]
	end

	slowo = Zaszyfrowane.new(wynik)
	slowo
    end

	def to_s
		@napis_jawny
	end

end
class Zaszyfrowane

    def initialize(napis_zaszyfrowany)
        @napis_zaszyfrowany = napis_zaszyfrowany
    end

    def odszyfruj(klucz)

	reverse_key = klucz.invert
        wynik = ""
	range = @napis_zaszyfrowany.length

        for i in 1..range do
            wynik += reverse_key[@napis_zaszyfrowany[i-1]]
	end

	slowo = Jawna.new(wynik)
	slowo
    end

    	def to_s()
       	 napis_zaszyfrowany.to_s
    	end
	def to_s
		@napis_zaszyfrowany
	end
end

slownik = {'a' => 'c', 'b' => 'd', 'c' => 'e', 'd' => 'f', 'e' => 'g', 
'f' => 'h', 'g' => 'i', 'h' => 'j', 'i' => 'k', 'j' => 'l', 'k' => 'm', 
'l' => 'n', 'm' => 'o', 'n' => 'p', 'o' => 'r', 'p' => 's', 'r' => 't', 
's' => 'u', 't' => 'w', 'u' => 'y', 'w' => 'z', 'y' => 'a', 'z' => 'b'}

slowo = Jawna.new("informatyka")
puts "slowo jawne:"
puts slowo.to_s
puts

slowo_zaszyfrowane = slowo.zaszyfruj(slownik)
puts "slowo zaszyfrowane:"
puts slowo_zaszyfrowane.to_s
puts

slow_odszyfrowane = slowo_zaszyfrowane.odszyfruj(slownik)
puts "slowo odszyfrowane:"
puts slow_odszyfrowane.to_s
