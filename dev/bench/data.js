window.BENCHMARK_DATA = {
  "lastUpdate": 1765914082859,
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
          "id": "76abd4e5b17cf76fdf645d97a5aa2fb81a604aec",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T20:36:55+01:00",
          "tree_id": "59adcbe858585bdc6e14de81de38827697bee311",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/76abd4e5b17cf76fdf645d97a5aa2fb81a604aec"
        },
        "date": 1765914053408,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 83.7604,
            "range": "± 12.0461",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 85.6526,
            "range": "± 13.3286",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 284.032,
            "range": "± 29.8688",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 218.334,
            "range": "± 33.4505",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 71.0209,
            "range": "± 6.76387",
            "unit": "ns",
            "extra": "100 samples\n425 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 83.8631,
            "range": "± 3.04745",
            "unit": "ns",
            "extra": "100 samples\n345 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 47.8325,
            "range": "± 6.69775",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 17.0923,
            "range": "± 2.29402",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 110.925,
            "range": "± 7.65587",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 44.9558,
            "range": "± 5.39045",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 85.421,
            "range": "± 23.575",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 79.9325,
            "range": "± 15.3078",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 144.23,
            "range": "± 4.29967",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 386.503,
            "range": "± 6.31012",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 42.5653,
            "range": "± 5.02819",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 46.5738,
            "range": "± 3.26827",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 50.2975,
            "range": "± 1.87931",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.7152,
            "range": "± 2.87715",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 80.898,
            "range": "± 6.93581",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 83.2045,
            "range": "± 9.71914",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.442,
            "range": "± 4.18886",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 141.18,
            "range": "± 3.40641",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ],
    "C++ Benchmark (x86_32)": [
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
          "id": "76abd4e5b17cf76fdf645d97a5aa2fb81a604aec",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T20:36:55+01:00",
          "tree_id": "59adcbe858585bdc6e14de81de38827697bee311",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/76abd4e5b17cf76fdf645d97a5aa2fb81a604aec"
        },
        "date": 1765914061428,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 351.601,
            "range": "± 8.19367",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 628.206,
            "range": "± 35.2698",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1.65543,
            "range": "± 44.5843",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1.37299,
            "range": "± 57.7909",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 112.741,
            "range": "± 3.84274",
            "unit": "ns",
            "extra": "100 samples\n349 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.5283,
            "range": "± 3.68602",
            "unit": "ns",
            "extra": "100 samples\n429 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.7006,
            "range": "± 1.64163",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.5849,
            "range": "± 521.601",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 128.48,
            "range": "± 5.13955",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 82.6526,
            "range": "± 4.41395",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 989.513,
            "range": "± 42.906",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 980.619,
            "range": "± 28.9817",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 151.291,
            "range": "± 4.37022",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 385.876,
            "range": "± 6.64907",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 40.869,
            "range": "± 4.55419",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 41.7365,
            "range": "± 4.96602",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.7959,
            "range": "± 2.95798",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.6526,
            "range": "± 2.3464",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 354.998,
            "range": "± 11.8329",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 354.361,
            "range": "± 9.88587",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.811,
            "range": "± 5.20564",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 344.23,
            "range": "± 4.54773",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ],
    "C++ Benchmark (arm64)": [
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
          "id": "76abd4e5b17cf76fdf645d97a5aa2fb81a604aec",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T20:36:55+01:00",
          "tree_id": "59adcbe858585bdc6e14de81de38827697bee311",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/76abd4e5b17cf76fdf645d97a5aa2fb81a604aec"
        },
        "date": 1765914071859,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 151.358,
            "range": "± 7.68896",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 151.294,
            "range": "± 6.82934",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 246.504,
            "range": "± 26.6933",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 242.666,
            "range": "± 24.8691",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.707,
            "range": "± 0.672344",
            "unit": "ns",
            "extra": "100 samples\n503 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 49.1623,
            "range": "± 0.485283",
            "unit": "ns",
            "extra": "100 samples\n642 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.1169,
            "range": "± 1.19218",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.8457,
            "range": "± 300.157",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 92.822,
            "range": "± 3.49511",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 30.6805,
            "range": "± 2.23554",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 49.9275,
            "range": "± 3.37221",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 64.9846,
            "range": "± 5.40749",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 158.995,
            "range": "± 17.5314",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 413.113,
            "range": "± 24.6983",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 65.4582,
            "range": "± 1.78311",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 66.3426,
            "range": "± 1.45806",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 59.57,
            "range": "± 1.24251",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 60.7963,
            "range": "± 1.63728",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 151.905,
            "range": "± 7.70187",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 152.803,
            "range": "± 8.56486",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.648,
            "range": "± 1.75017",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 111.26,
            "range": "± 4.03214",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ],
    "C++ Benchmark (arm32)": [
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
          "id": "76abd4e5b17cf76fdf645d97a5aa2fb81a604aec",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T20:36:55+01:00",
          "tree_id": "59adcbe858585bdc6e14de81de38827697bee311",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/76abd4e5b17cf76fdf645d97a5aa2fb81a604aec"
        },
        "date": 1765914082357,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 1.90499,
            "range": "± 5.90852",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1.90301,
            "range": "± 4.9476",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4.40347,
            "range": "± 200.792",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4.43845,
            "range": "± 208.94",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1.0771,
            "range": "± 5.22527",
            "unit": "us",
            "extra": "100 samples\n260 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 774.849,
            "range": "± 3.96119",
            "unit": "ns",
            "extra": "100 samples\n360 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 348.074,
            "range": "± 2.80165",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 127.756,
            "range": "± 662.302",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 469.872,
            "range": "± 6.22821",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 335.686,
            "range": "± 6.62898",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2.09236,
            "range": "± 29.59",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2.09294,
            "range": "± 29.4602",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 339.39,
            "range": "± 5.83938",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 886.891,
            "range": "± 4.21111",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 250.278,
            "range": "± 4.24864",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 248.403,
            "range": "± 1.40884",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 264.476,
            "range": "± 6.07995",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 262.007,
            "range": "± 2.27971",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1.90215,
            "range": "± 4.79414",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1.90684,
            "range": "± 8.07074",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1.8782,
            "range": "± 8.61876",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1.64553,
            "range": "± 5.0083",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}
