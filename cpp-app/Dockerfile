FROM drogonframework/drogon as build

WORKDIR /app

COPY . .

RUN cmake -S . -B build
RUN cmake --build build --config Release

FROM drogonframework/drogon as run

COPY --from=build /app/build/cpp_app /cpp_app

CMD ["/cpp_app"]
