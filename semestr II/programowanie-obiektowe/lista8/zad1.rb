#Piotr Stoklosa zad1
class Fixnum

	def czynniki

		tab = []
		range = (Math.sqrt(self)).floor

		for i in 1..range do
			if self%i == 0

				tab.push(i)

				if i != self/i
					tab.push(self / i)
				end
			end
		end

		tab
	end

	def ack(y)

		if self == 0
			y + 1

		elsif y == 0
			(self-1).ack(1)

		else
			(self-1).ack(self.ack(y-1))

		end
	end

	def doskonala

		tab = self.czynniki
		sum = 0

		for i in tab do
			sum+=i	
		end

		sum == self * 2
			
	end

	def slownie

		slownik ={1 => "jeden", 2 => "dwa", 3 => "trzy", 4 => "cztery", 5 => "pięć", 6 => "sześć", 7 => "siedem", 8 => "osiem", 9 => "dziewięć", 0 => "zero"}
		x = self.to_s.reverse.to_i
		wynik=""

		while x>0

			wynik+=slownik[x%10]
			wynik+=' '
			x = x/10

		end

		wynik
	end
end

puts "\nDzielniki liczby 6:"
print 6.czynniki
puts "\n\nDzielniki liczby 78:"
print 78.czynniki
print "\n\n\n"

puts "Ack(2,1):"
puts 2.ack(1)
puts "\nAck(2,2):"
puts 2.ack(2)
print "\n\n"

puts "Czy liczba 7 jest doskonała?"
puts 7.doskonala
puts "\nCzy liczba 6 jest doskonała?"
puts 6.doskonala
print "\n\n"

puts "123 słownie:"
puts 123.slownie
puts "\n98345 słownie:"
puts 98345.slownie
print "\n"
