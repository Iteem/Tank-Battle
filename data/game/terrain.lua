function create(t)
	local h = 300
	for i = 0, 799 do
		h = h + math.random(-5, 5)
		for j = h, 599 do
			t:setPixel(i,j)
		end
	end
	return
end