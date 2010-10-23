--classic algorithm using parable to create the terrain

function create(t)
	math.randomseed( os.time() ); math.random(); -- the first random number seems to be not very random ;)
	local P2
	local P0 
	for k = 0, 7 do
		if k == 0 then
			P0 = math.random(230, 450)
		else 
			P0 = P2
		end
		P2 = math.random(230, 450)
		
		local P1 = (P0 + P2) / 2
		
		parable(t, k * 100,      k * 100 + 50, P0, P1, true)
		parable(t, k * 100 + 50, k * 100 + 99, P1, P2, false)
	end
end

function parable(t, x1, x2, y1, y2, w)
	v = y1 < y2 and 1 or -1
	local root = math.sqrt(math.abs(y2 - y1))
	local x = x2 - x1
	
	local b = w and x1 or x2
	local c = w and y1 or y2
	v = w and v or v * -1
	
	for i = x1, x2 do
		local h1 = 600 - c - math.pow(root / x * math.abs(i-b),2) * v
		local h = math.floor(h1)
		h1 = h1 - h
		t:setPixel(i,h-1, Color(0, 0, 0, 255 * (1 - h1)));
		for j = h, 599 do
			t:setPixel(i,j, Color(0, 0, 0, 255));
		end
	end
	return 
end
