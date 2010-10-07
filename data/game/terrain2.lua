function create()
	local NumberOfPoints = math.random(5, 7)
    local NumberOfPointsT = NumberOfPoints*2-1
    PointsY = {}--int *PointsY = new int[NumberOfPointsT];
    PointsX = {}--int *PointsX = new int[NumberOfPointsT];
	
	for i = 1, NumberOfPointsT do
		PointsY[i] = 0
		PointsX[i] = 0
	end
	
    for i = 1, NumberOfPoints do
        PointsY[2*i] = math.random(280, 500)
		io.write(i)
        h = PointsY[2*i]-PointsY[2*i-2]
        if h < 50 and h > -50 then
            i = i - 1
		end
    end
	
	--[[
    for i = 1, NumberOfPointsT,2 do
        PointsY(i) = (PointsY(i-1) + PointsY(i+1)) / 2
	end
    for i = 0, NumberOfPointsT do
        PointsX(i) = 800 / (NumberOfPointsT - 1) * i
	end
    for i = 2, NumberOfPointsT - 2, 2 do
        PointsX(i) = PointsX(i) + math.random(-10, 10)
	end

    for i = 0, NumberOfPointsT - 1 do
        if i%2 != 0 then
            Sx = PointsX(i+1)
            Sy = PointsY(i+1)
            Px = PointsX(i)
            Py = PointsY(i)
        else
            Sx = PointsX(i);
            Sy = PointsY(i);
            Px = PointsX(i+1);
            Py = PointsY(i+1);
        end

        a = (Py-Sy)/((Px-Sx)*(Px-Sx))

        for j = PointsX[i], PointsX[i+1] do
			for k = 0, a * (math.pow(j-Sx,2)) + Sy do
				SetPixel(j, k)
			end
		end
    end
	]]--
	return
end
