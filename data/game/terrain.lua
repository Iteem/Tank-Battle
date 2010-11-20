--classic algorithm using parable to create the terrain

function create(t, w, h)
	math.randomseed( os.time() ); math.random(); -- the first random number seems to be not very random ;)
	local P2, P0 
	local cw = w/800
	local ch = h/600
	for k = 0, 7 do
		if k == 0 then
			P0 = math.random(230*ch, 450*ch)
		else 
			P0 = P2
		end
		P2 = math.random(230*ch, 450*ch)
		
		local P1 = (P0 + P2) / 2
		
		parable(t, (k * 100) * cw,     (k * 100 + 50)*cw, P0, P1, true, h)
		parable(t, (k * 100 + 50) *cw, (k * 100 + 100)*cw, P1, P2, false, h)
	end
end

function parable(t, x1, x2, y1, y2, w, height)
	v = y1 < y2 and 1 or -1
	local root = math.sqrt(math.abs(y2 - y1))
	local x = x2 - x1
	
	local b = w and x1 or x2
	local c = w and y1 or y2
	v = w and v or v * -1
	
	for i = x1, x2 do
		local h1 = height - c - math.pow(root / x * math.abs(i-b),2) * v
		local h = math.floor(h1)
		h1 = h1 - h
		t:setPixel(i,h-1, Color(0, 0, 0, 255 * (1 - h1)));
		t:fill(i, h, Color( 0, 0, 0, 255));
		--for j = h, height-1 do
			--t:setPixel(i,j, Color(0, 0, 0, 255));
		--end
	end
	return 
end
