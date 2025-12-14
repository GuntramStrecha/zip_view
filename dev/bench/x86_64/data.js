window.BENCHMARK_DATA = {
  "lastUpdate": 1765743765265,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark (x86_64)": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "6a7cbd2823f2645cab07fb49b5aea967d0e4fe80",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T18:46:01+01:00",
          "tree_id": "e316f8f3bb299fdcc64eedc68170806c99df0874",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/6a7cbd2823f2645cab07fb49b5aea967d0e4fe80"
        },
        "date": 1765734614689,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 124.562,
            "range": "± 21.8987",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 124.414,
            "range": "± 19.0146",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 498.853,
            "range": "± 55.0835",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 499.899,
            "range": "± 56.994",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 64.7455,
            "range": "± 2.34897",
            "unit": "ns",
            "extra": "100 samples\n275 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 71.3695,
            "range": "± 2.53521",
            "unit": "ns",
            "extra": "100 samples\n252 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 56.8669,
            "range": "± 1.26054",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 21.7208,
            "range": "± 1.11863",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 115.796,
            "range": "± 6.1275",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 65.6827,
            "range": "± 7.72963",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 133.184,
            "range": "± 17.1378",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 133,
            "range": "± 15.1197",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 204.772,
            "range": "± 30.6996",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 624.931,
            "range": "± 46.9918",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 53.5417,
            "range": "± 2.781",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 53.4811,
            "range": "± 2.71553",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.8638,
            "range": "± 3.51893",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 57.9251,
            "range": "± 2.97993",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 129.302,
            "range": "± 18.2877",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 129.984,
            "range": "± 20.8987",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 169.077,
            "range": "± 3.51755",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 113.28,
            "range": "± 3.69333",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "7444114e0d708342d33f29966494b22b0570c40d",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T18:58:06+01:00",
          "tree_id": "1565a65a55732830ff7703be2d557929b207ea23",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/7444114e0d708342d33f29966494b22b0570c40d"
        },
        "date": 1765735211212,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 82.9371,
            "range": "± 12.3634",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 83.586,
            "range": "± 11.9722",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 278.694,
            "range": "± 26.3592",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 216.308,
            "range": "± 38.2085",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 70.6377,
            "range": "± 4.57078",
            "unit": "ns",
            "extra": "100 samples\n425 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 83.8266,
            "range": "± 3.38729",
            "unit": "ns",
            "extra": "100 samples\n345 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 47.9375,
            "range": "± 4.0944",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 16.3654,
            "range": "± 1.5403",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 111.28,
            "range": "± 4.60377",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 55.659,
            "range": "± 4.90771",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 72.8645,
            "range": "± 13.9618",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 79.1276,
            "range": "± 19.5839",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 146.012,
            "range": "± 9.03026",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 392.611,
            "range": "± 29.3799",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 42.4244,
            "range": "± 5.34074",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 45.0377,
            "range": "± 4.8533",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 50.2074,
            "range": "± 1.95674",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 64.9138,
            "range": "± 6.40126",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 89.0722,
            "range": "± 18.9026",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 87.1051,
            "range": "± 18.6464",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.277,
            "range": "± 3.86874",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 140.727,
            "range": "± 3.06453",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "5900b5935264621bb7b7b332e48f842a5da935c9",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T21:20:19+01:00",
          "tree_id": "d09077e0ded4cc83602fec81e0a6c0aa43887319",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/5900b5935264621bb7b7b332e48f842a5da935c9"
        },
        "date": 1765743764860,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 87.1979,
            "range": "± 20.5493",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 86.5144,
            "range": "± 13.3934",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 305.636,
            "range": "± 34.906",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 285.816,
            "range": "± 33.0974",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 71.3404,
            "range": "± 6.32433",
            "unit": "ns",
            "extra": "100 samples\n427 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 85.9315,
            "range": "± 3.47419",
            "unit": "ns",
            "extra": "100 samples\n341 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 49.9137,
            "range": "± 6.22388",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 18.0661,
            "range": "± 3.50591",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 111.546,
            "range": "± 8.0021",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 46.0481,
            "range": "± 4.2784",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 77.308,
            "range": "± 8.96847",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 82.8023,
            "range": "± 13.4968",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 149.432,
            "range": "± 17.2678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 392.986,
            "range": "± 30.8165",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 45.8,
            "range": "± 7.53344",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 49.1262,
            "range": "± 5.75858",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 52.1024,
            "range": "± 3.70122",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 66.8508,
            "range": "± 9.92333",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 88.4426,
            "range": "± 19.8476",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 92.3313,
            "range": "± 17.4287",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.37,
            "range": "± 4.01627",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 140.864,
            "range": "± 3.281",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}