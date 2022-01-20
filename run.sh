for i in 200 300 400 500 600 700 800 900 1000
    do
    for time in $(seq 1 5)
        do
        ./a.exe $i connect_$i\_$time.txt
        done
    done
