window.BENCHMARK_DATA = {
  "lastUpdate": 1765919942422,
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
          "id": "446c9f65aff095acd6ccf3b32af0a5eef7257890",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:14:07+01:00",
          "tree_id": "cc373b750931c2b9bfae59f78eb88b7270a4fc7e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/446c9f65aff095acd6ccf3b32af0a5eef7257890"
        },
        "date": 1765919908322,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 82.8394,
            "range": "± 12.4271",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 96.3547,
            "range": "± 25.9214",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 303.171,
            "range": "± 24.0571",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 280.875,
            "range": "± 36.4507",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 69.9606,
            "range": "± 4.34359",
            "unit": "ns",
            "extra": "100 samples\n424 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 83.6979,
            "range": "± 2.97685",
            "unit": "ns",
            "extra": "100 samples\n345 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 49.7221,
            "range": "± 5.26914",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 17.0739,
            "range": "± 2.27577",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 112.156,
            "range": "± 10.636",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 43.8505,
            "range": "± 3.03194",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 77.7206,
            "range": "± 7.26634",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 78.6572,
            "range": "± 9.38401",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 150.956,
            "range": "± 13.1863",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 389.167,
            "range": "± 15.6205",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 42.048,
            "range": "± 8.61315",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 46.3833,
            "range": "± 5.35947",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 51.6309,
            "range": "± 4.71797",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 63.146,
            "range": "± 2.88512",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 86.2168,
            "range": "± 19.3375",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 83.0286,
            "range": "± 10.0044",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.346,
            "range": "± 3.90631",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 140.78,
            "range": "± 3.25039",
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
          "id": "446c9f65aff095acd6ccf3b32af0a5eef7257890",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:14:07+01:00",
          "tree_id": "cc373b750931c2b9bfae59f78eb88b7270a4fc7e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/446c9f65aff095acd6ccf3b32af0a5eef7257890"
        },
        "date": 1765919920102,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 362.187,
            "range": "± 7.48243",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 624.636,
            "range": "± 9.48732",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1.66994,
            "range": "± 26.1511",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1.35994,
            "range": "± 30.1389",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 112.768,
            "range": "± 3.86734",
            "unit": "ns",
            "extra": "100 samples\n350 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.057,
            "range": "± 3.23503",
            "unit": "ns",
            "extra": "100 samples\n428 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.6705,
            "range": "± 1.642",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.6067,
            "range": "± 656.831",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 129.026,
            "range": "± 13.3572",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 82.4996,
            "range": "± 3.45539",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 977.444,
            "range": "± 21.1924",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 980.069,
            "range": "± 21.4889",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 151.231,
            "range": "± 4.38901",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 382.563,
            "range": "± 5.41008",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 45.1813,
            "range": "± 4.79722",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 46.6829,
            "range": "± 2.9843",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.9838,
            "range": "± 2.98199",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.3874,
            "range": "± 2.04045",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 354.28,
            "range": "± 8.54262",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 356.876,
            "range": "± 8.15118",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.42,
            "range": "± 4.30021",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 345.075,
            "range": "± 5.65315",
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
          "id": "446c9f65aff095acd6ccf3b32af0a5eef7257890",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:14:07+01:00",
          "tree_id": "cc373b750931c2b9bfae59f78eb88b7270a4fc7e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/446c9f65aff095acd6ccf3b32af0a5eef7257890"
        },
        "date": 1765919932526,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 151.175,
            "range": "± 6.67157",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 151.882,
            "range": "± 7.94025",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 257.827,
            "range": "± 21.4405",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 245.812,
            "range": "± 20.9991",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.4732,
            "range": "± 0.901301",
            "unit": "ns",
            "extra": "100 samples\n506 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 48.8936,
            "range": "± 0.939013",
            "unit": "ns",
            "extra": "100 samples\n647 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.1487,
            "range": "± 1.22381",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.8834,
            "range": "± 324.353",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 93.4761,
            "range": "± 3.69987",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 30.5738,
            "range": "± 3.59781",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 66.9187,
            "range": "± 5.21451",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 72.2378,
            "range": "± 4.93721",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 155.866,
            "range": "± 18.7213",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 416.482,
            "range": "± 27.6184",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 66.6093,
            "range": "± 1.67076",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 66.8038,
            "range": "± 2.68087",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 61.0118,
            "range": "± 1.66317",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 60.8435,
            "range": "± 1.25111",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 151.466,
            "range": "± 7.68619",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 154.401,
            "range": "± 9.51485",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.677,
            "range": "± 1.86843",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 110.446,
            "range": "± 2.14111",
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
          "id": "446c9f65aff095acd6ccf3b32af0a5eef7257890",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:14:07+01:00",
          "tree_id": "cc373b750931c2b9bfae59f78eb88b7270a4fc7e",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/446c9f65aff095acd6ccf3b32af0a5eef7257890"
        },
        "date": 1765919942108,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 1.90367,
            "range": "± 5.28663",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1.90409,
            "range": "± 4.24024",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4.42865,
            "range": "± 214.738",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4.42211,
            "range": "± 205.813",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1.0711,
            "range": "± 5.88442",
            "unit": "us",
            "extra": "100 samples\n262 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 770.671,
            "range": "± 5.1218",
            "unit": "ns",
            "extra": "100 samples\n365 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 347.945,
            "range": "± 2.47466",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 128.829,
            "range": "± 731.092",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 472.32,
            "range": "± 6.70311",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 337.896,
            "range": "± 6.82688",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2.09546,
            "range": "± 29.5273",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2.1153,
            "range": "± 27.1026",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 341.81,
            "range": "± 10.2989",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 888.474,
            "range": "± 5.70988",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 248.318,
            "range": "± 1.9497",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 248.541,
            "range": "± 1.822",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 261.187,
            "range": "± 1.8632",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 261.86,
            "range": "± 3.12",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1.9057,
            "range": "± 6.68443",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1.90394,
            "range": "± 4.4706",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1.88613,
            "range": "± 6.55591",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1.64199,
            "range": "± 5.61893",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}