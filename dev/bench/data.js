window.BENCHMARK_DATA = {
  "lastUpdate": 1765962489270,
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
          "id": "f763ac136fa27d3e2691519fe1d9c8967994bbd0",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:37:39+01:00",
          "tree_id": "f292fc0421107aa466aefcfaab702572d0cd6fb5",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/f763ac136fa27d3e2691519fe1d9c8967994bbd0"
        },
        "date": 1765921315091,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 87.4787,
            "range": "± 22.5859",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 89.0473,
            "range": "± 28.685",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 306.553,
            "range": "± 42.4109",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 285.156,
            "range": "± 44.1322",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 77.9749,
            "range": "± 12.6643",
            "unit": "ns",
            "extra": "100 samples\n425 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 89.5803,
            "range": "± 7.83571",
            "unit": "ns",
            "extra": "100 samples\n345 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 47.31,
            "range": "± 2.61131",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 17.2881,
            "range": "± 2.4416",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 110.038,
            "range": "± 4.61965",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 45.2886,
            "range": "± 3.25515",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 81.8403,
            "range": "± 22.5831",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 83.6141,
            "range": "± 24.7451",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 147.439,
            "range": "± 14.8239",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 393.359,
            "range": "± 47.9162",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 50.0379,
            "range": "± 8.01786",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 50.6032,
            "range": "± 5.89364",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 52.7769,
            "range": "± 6.13888",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 64.7905,
            "range": "± 6.32319",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 87.6601,
            "range": "± 21.49",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 87.9633,
            "range": "± 20.9789",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.287,
            "range": "± 3.85666",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 141.047,
            "range": "± 3.38818",
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
          "id": "f763ac136fa27d3e2691519fe1d9c8967994bbd0",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:37:39+01:00",
          "tree_id": "f292fc0421107aa466aefcfaab702572d0cd6fb5",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/f763ac136fa27d3e2691519fe1d9c8967994bbd0"
        },
        "date": 1765921323053,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 364.91,
            "range": "± 16.0353",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 625.326,
            "range": "± 10.6219",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 2.36049,
            "range": "± 53.4974",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 2.10994,
            "range": "± 81.053",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 119.088,
            "range": "± 9.49813",
            "unit": "ns",
            "extra": "100 samples\n344 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 97.2539,
            "range": "± 5.98208",
            "unit": "ns",
            "extra": "100 samples\n416 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.8761,
            "range": "± 1.95127",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 16.2626,
            "range": "± 1.06077",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 125.935,
            "range": "± 5.54979",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 82.2101,
            "range": "± 4.33336",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 964.882,
            "range": "± 14.7356",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 971.474,
            "range": "± 23.4153",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 152.239,
            "range": "± 4.2575",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 385.509,
            "range": "± 11.4659",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 44.082,
            "range": "± 6.18756",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 44.7602,
            "range": "± 5.40115",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 54.0339,
            "range": "± 2.89308",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 63.5138,
            "range": "± 3.52228",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 352.57,
            "range": "± 26.6942",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 349.435,
            "range": "± 9.61243",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.181,
            "range": "± 4.34192",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 343.962,
            "range": "± 5.13397",
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
          "id": "f763ac136fa27d3e2691519fe1d9c8967994bbd0",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:37:39+01:00",
          "tree_id": "f292fc0421107aa466aefcfaab702572d0cd6fb5",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/f763ac136fa27d3e2691519fe1d9c8967994bbd0"
        },
        "date": 1765921331666,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 149.425,
            "range": "± 6.18498",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 149.996,
            "range": "± 8.40011",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 253.757,
            "range": "± 16.2318",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 230.311,
            "range": "± 25.9254",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.6992,
            "range": "± 0.642538",
            "unit": "ns",
            "extra": "100 samples\n503 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 49.1727,
            "range": "± 0.537701",
            "unit": "ns",
            "extra": "100 samples\n639 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.0344,
            "range": "± 1.37605",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.5183,
            "range": "± 400.386",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 91.7929,
            "range": "± 3.71096",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 30.1799,
            "range": "± 2.52675",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 63.4619,
            "range": "± 12.7432",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 61.4033,
            "range": "± 4.34569",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 152.412,
            "range": "± 15.8699",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 412.355,
            "range": "± 21.6146",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 66.4431,
            "range": "± 1.51156",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 65.8938,
            "range": "± 2.39768",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 61.0687,
            "range": "± 3.23504",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 60.6295,
            "range": "± 1.12106",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 150.003,
            "range": "± 7.32412",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 150.607,
            "range": "± 8.38594",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.585,
            "range": "± 1.72054",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 110.238,
            "range": "± 2.27509",
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
          "id": "f763ac136fa27d3e2691519fe1d9c8967994bbd0",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:37:39+01:00",
          "tree_id": "f292fc0421107aa466aefcfaab702572d0cd6fb5",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/f763ac136fa27d3e2691519fe1d9c8967994bbd0"
        },
        "date": 1765921341408,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 1.90839,
            "range": "± 15.8703",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1.90837,
            "range": "± 14.8556",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4.34519,
            "range": "± 197.541",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4.3391,
            "range": "± 182.593",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1.06693,
            "range": "± 4.82686",
            "unit": "us",
            "extra": "100 samples\n263 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 766.458,
            "range": "± 4.95865",
            "unit": "ns",
            "extra": "100 samples\n366 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 348.415,
            "range": "± 3.43487",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 128.075,
            "range": "± 747.381",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 469.439,
            "range": "± 6.38075",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 336.562,
            "range": "± 6.61273",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2.09446,
            "range": "± 28.8064",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2.10554,
            "range": "± 27.877",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 340.356,
            "range": "± 4.69145",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 886.35,
            "range": "± 9.99592",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 248.154,
            "range": "± 1.7528",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 248.416,
            "range": "± 1.51686",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 261.435,
            "range": "± 1.85169",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 261.343,
            "range": "± 1.46842",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1.90517,
            "range": "± 8.1616",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1.90598,
            "range": "± 8.67527",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1.88716,
            "range": "± 10.2504",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1.64579,
            "range": "± 5.80596",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ],
    "C++ Benchmark": [
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
          "id": "fdfcda6760f7eaf7bfee95fa565b9136c7dd3398",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T22:43:06+01:00",
          "tree_id": "c82d00e88437bd6e1efd9742a22c4d2a9c0ace85",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/fdfcda6760f7eaf7bfee95fa565b9136c7dd3398"
        },
        "date": 1765921710366,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 84.3311,
            "range": "± 14.1204",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 81.6748,
            "range": "± 11.4021",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 289.912,
            "range": "± 33.4191",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 232.41,
            "range": "± 55.382",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 69.7732,
            "range": "± 4.36989",
            "unit": "ns",
            "extra": "100 samples\n426 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 83.9688,
            "range": "± 3.29835",
            "unit": "ns",
            "extra": "100 samples\n344 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 48.7963,
            "range": "± 4.0345",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 17.1689,
            "range": "± 2.7196",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 110.205,
            "range": "± 3.90953",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 53.5619,
            "range": "± 7.34468",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 81.6038,
            "range": "± 15.4678",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 77.7292,
            "range": "± 13.2097",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 145.798,
            "range": "± 9.62674",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 391.881,
            "range": "± 17.2924",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 43.3421,
            "range": "± 5.16947",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 46.3106,
            "range": "± 6.31906",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 51.1305,
            "range": "± 2.47245",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 64.543,
            "range": "± 4.71006",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 84.8355,
            "range": "± 13.8641",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 85.7023,
            "range": "± 13.2201",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.16,
            "range": "± 3.7346",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 141.077,
            "range": "± 3.73502",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 361.858,
            "range": "± 7.2052",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 623.549,
            "range": "± 5.17388",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1.63741,
            "range": "± 11.9109",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1.33799,
            "range": "± 14.0488",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 114.166,
            "range": "± 8.09747",
            "unit": "ns",
            "extra": "100 samples\n344 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.9471,
            "range": "± 5.62903",
            "unit": "ns",
            "extra": "100 samples\n413 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.7094,
            "range": "± 1.75087",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.7997,
            "range": "± 781.204",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 124.325,
            "range": "± 3.05438",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 80.6623,
            "range": "± 2.47065",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 963.129,
            "range": "± 7.09102",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 963.852,
            "range": "± 6.62492",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 150.632,
            "range": "± 3.67286",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 382.072,
            "range": "± 4.97648",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 45.1233,
            "range": "± 4.61198",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 45.9397,
            "range": "± 4.58005",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.5632,
            "range": "± 2.71945",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.4827,
            "range": "± 2.22394",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 355.341,
            "range": "± 18.7611",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 356.506,
            "range": "± 7.97821",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.387,
            "range": "± 4.26658",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 343.588,
            "range": "± 4.19524",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 149.763,
            "range": "± 6.1032",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 150.777,
            "range": "± 7.02377",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 234.304,
            "range": "± 24.0254",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 233.684,
            "range": "± 24.6131",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.6786,
            "range": "± 0.787868",
            "unit": "ns",
            "extra": "100 samples\n503 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 49.2893,
            "range": "± 0.452977",
            "unit": "ns",
            "extra": "100 samples\n638 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.0827,
            "range": "± 1.20547",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.9105,
            "range": "± 552.056",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 92.6435,
            "range": "± 2.94448",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 30.3972,
            "range": "± 2.30933",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 53.1889,
            "range": "± 5.24205",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 50.5072,
            "range": "± 3.1462",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 156.082,
            "range": "± 16.8314",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 413.798,
            "range": "± 24.7322",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 66.4165,
            "range": "± 1.32855",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 66.3669,
            "range": "± 1.38473",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 60.55,
            "range": "± 1.20374",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 60.6356,
            "range": "± 1.26094",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 151.056,
            "range": "± 7.39098",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 150.878,
            "range": "± 9.11126",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.71,
            "range": "± 2.48363",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 111.036,
            "range": "± 3.4762",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 1.90842,
            "range": "± 7.34902",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1.908,
            "range": "± 5.11556",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4.35738,
            "range": "± 201.245",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4.42148,
            "range": "± 207.755",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1.07478,
            "range": "± 4.7165",
            "unit": "us",
            "extra": "100 samples\n259 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 769.288,
            "range": "± 3.88211",
            "unit": "ns",
            "extra": "100 samples\n360 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 348.202,
            "range": "± 2.89722",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 128.831,
            "range": "± 1.07251",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 472.139,
            "range": "± 6.8652",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 337.746,
            "range": "± 10.6697",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2.10703,
            "range": "± 37.4268",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2.10704,
            "range": "± 35.0183",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 339.318,
            "range": "± 4.4184",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 886.796,
            "range": "± 10.1437",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 248.864,
            "range": "± 2.10295",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 249.393,
            "range": "± 3.72888",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 262.141,
            "range": "± 2.48016",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 261.743,
            "range": "± 1.74661",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1.9071,
            "range": "± 5.90592",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1.9086,
            "range": "± 6.07858",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1.88765,
            "range": "± 6.80063",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1.64125,
            "range": "± 4.85257",
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
          "id": "edf629a4da399e4b5a0290fcc5967fb085dc4dcc",
          "message": "fixup! Add arm support for CI",
          "timestamp": "2025-12-16T23:07:36+01:00",
          "tree_id": "c818da9b870a2f4896e6a32c9603f785e1ed4ca9",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/edf629a4da399e4b5a0290fcc5967fb085dc4dcc"
        },
        "date": 1765923185408,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 96.4944,
            "range": "± 21.5607",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 98.8235,
            "range": "± 20.1434",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 319.519,
            "range": "± 48.8791",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 289.87,
            "range": "± 45.314",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 74.1534,
            "range": "± 11.4224",
            "unit": "ns",
            "extra": "100 samples\n426 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 85.6559,
            "range": "± 3.65544",
            "unit": "ns",
            "extra": "100 samples\n340 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 50.3663,
            "range": "± 7.78801",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 18.2554,
            "range": "± 3.60627",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 113.31,
            "range": "± 12.1269",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 48.6961,
            "range": "± 7.73752",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 89.2479,
            "range": "± 26.0124",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 89.363,
            "range": "± 18.3989",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 160.03,
            "range": "± 25.2399",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 396.906,
            "range": "± 37.3627",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 46.0593,
            "range": "± 8.45181",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 50.7723,
            "range": "± 6.0867",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 52.1939,
            "range": "± 4.06145",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 66.7497,
            "range": "± 9.8946",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 98.4245,
            "range": "± 22.8013",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 101.915,
            "range": "± 26.5277",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.362,
            "range": "± 4.08092",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 141.591,
            "range": "± 3.93051",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 370.867,
            "range": "± 9.76831",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 624.939,
            "range": "± 5.37397",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 1639.83,
            "range": "± 26419",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1340.74,
            "range": "± 28707.5",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 114.005,
            "range": "± 9.73048",
            "unit": "ns",
            "extra": "100 samples\n350 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 92.6372,
            "range": "± 4.77368",
            "unit": "ns",
            "extra": "100 samples\n430 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.8407,
            "range": "± 1.96272",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.5816,
            "range": "± 493.993",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 125.301,
            "range": "± 4.00648",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 81.5974,
            "range": "± 3.2916",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 1681.25,
            "range": "± 24562.7",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 1679.49,
            "range": "± 15128",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 151.597,
            "range": "± 4.14092",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 386.224,
            "range": "± 7.2531",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 45.6647,
            "range": "± 4.34994",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 44.079,
            "range": "± 5.33916",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 54.1082,
            "range": "± 3.30704",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.5224,
            "range": "± 2.25462",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 368.231,
            "range": "± 11.737",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 364.782,
            "range": "± 14.1242",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.734,
            "range": "± 4.52077",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 344.058,
            "range": "± 5.17455",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 149.808,
            "range": "± 5.70182",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 149.978,
            "range": "± 7.3808",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 231.197,
            "range": "± 23.11",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 232.158,
            "range": "± 20.3823",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.7326,
            "range": "± 1.02604",
            "unit": "ns",
            "extra": "100 samples\n503 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 49.2256,
            "range": "± 0.447677",
            "unit": "ns",
            "extra": "100 samples\n638 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.0959,
            "range": "± 1.3158",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 14.549,
            "range": "± 824.718",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 91.8776,
            "range": "± 2.74518",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 30.634,
            "range": "± 2.00388",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 61.6932,
            "range": "± 6.63781",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 55.4736,
            "range": "± 10.9285",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 155.243,
            "range": "± 15.5772",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 410.434,
            "range": "± 21.4612",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 66.755,
            "range": "± 1.87951",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 66.5643,
            "range": "± 1.52845",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 60.9583,
            "range": "± 1.55999",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 61.2445,
            "range": "± 2.38249",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 151.011,
            "range": "± 11.3257",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 150.651,
            "range": "± 8.4108",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.585,
            "range": "± 2.32259",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 110.123,
            "range": "± 1.93306",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 1902.48,
            "range": "± 5357.15",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1903.3700000000001,
            "range": "± 4740.05",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4408.95,
            "range": "± 196214",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4424.16,
            "range": "± 206046",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1070.8,
            "range": "± 6522.509999999999",
            "unit": "ns",
            "extra": "100 samples\n262 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 764.231,
            "range": "± 3.70724",
            "unit": "ns",
            "extra": "100 samples\n364 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 346.734,
            "range": "± 3.10396",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 128.438,
            "range": "± 647.009",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 470.216,
            "range": "± 5.32367",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 338.465,
            "range": "± 9.88106",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2090.78,
            "range": "± 21228.3",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2093.54,
            "range": "± 26268",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 338.011,
            "range": "± 3.06943",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 884.422,
            "range": "± 6.15935",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 248.29,
            "range": "± 1.54535",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 249.644,
            "range": "± 5.3836",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 262.157,
            "range": "± 4.40699",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 261.162,
            "range": "± 1.34073",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1904.74,
            "range": "± 7054.160000000001",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1904.56,
            "range": "± 7192.9400000000005",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1885.74,
            "range": "± 8071.09",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1640.25,
            "range": "± 4535.83",
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
          "id": "3bd9d399c0dece77c05544a02923a76dd042eb49",
          "message": "Add more benchmarks",
          "timestamp": "2025-12-14T18:10:15+01:00",
          "tree_id": "a1e8d73584e5df745e80856e7fb9e038e83b410a",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/3bd9d399c0dece77c05544a02923a76dd042eb49"
        },
        "date": 1765960712728,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 81.1472,
            "range": "± 6.83487",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 82.4398,
            "range": "± 7.86842",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 301.654,
            "range": "± 38.2288",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 273.096,
            "range": "± 29.8105",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 69.0719,
            "range": "± 3.25665",
            "unit": "ns",
            "extra": "100 samples\n427 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 84.682,
            "range": "± 3.55537",
            "unit": "ns",
            "extra": "100 samples\n343 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 47.2088,
            "range": "± 2.44783",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 16.3043,
            "range": "± 1.28714",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 111.008,
            "range": "± 6.35354",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 44.929,
            "range": "± 5.13343",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 68.3161,
            "range": "± 18.4605",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 63.0371,
            "range": "± 8.44447",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 144.79,
            "range": "± 6.02567",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 386.129,
            "range": "± 8.34174",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 41.0894,
            "range": "± 4.82106",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 42.8537,
            "range": "± 7.56406",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 50.5988,
            "range": "± 2.64924",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.7317,
            "range": "± 2.47453",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 81.5155,
            "range": "± 7.27281",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 83.2183,
            "range": "± 9.35813",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.856,
            "range": "± 5.57682",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 140.751,
            "range": "± 3.62154",
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
            "email": "noreply@github.com",
            "name": "GitHub",
            "username": "web-flow"
          },
          "distinct": true,
          "id": "45ad016f2afcee4d9db7151e897ca44bfb0a8249",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-17T10:04:08+01:00",
          "tree_id": "9cc25d17f61f570dff83aa21bab6516571ddb70c",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/45ad016f2afcee4d9db7151e897ca44bfb0a8249"
        },
        "date": 1765962488730,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 93.4126,
            "range": "± 19.0973",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 93.5217,
            "range": "± 20.6468",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 306.288,
            "range": "± 35.6922",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 289.399,
            "range": "± 36.946",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 72.4627,
            "range": "± 7.2604",
            "unit": "ns",
            "extra": "100 samples\n425 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 84.7253,
            "range": "± 3.42056",
            "unit": "ns",
            "extra": "100 samples\n343 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 48.7,
            "range": "± 3.44158",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 16.7522,
            "range": "± 1.72626",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 110.683,
            "range": "± 5.6008",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 57.0826,
            "range": "± 4.54347",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 83.1901,
            "range": "± 23.3401",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 86.0764,
            "range": "± 21.1167",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 149.488,
            "range": "± 11.8094",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 392.328,
            "range": "± 21.7506",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 43.6885,
            "range": "± 8.61588",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 44.0112,
            "range": "± 5.46084",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 50.3983,
            "range": "± 2.81147",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 66.5017,
            "range": "± 9.26526",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 88.6649,
            "range": "± 18.7877",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 91.8769,
            "range": "± 19.8126",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.042,
            "range": "± 3.7176",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 140.652,
            "range": "± 3.12195",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 364.644,
            "range": "± 14.4341",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 624.135,
            "range": "± 8.39726",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 2068.33,
            "range": "± 489867",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 1389.69,
            "range": "± 51199.7",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 114.386,
            "range": "± 4.52609",
            "unit": "ns",
            "extra": "100 samples\n345 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 94.9365,
            "range": "± 4.96589",
            "unit": "ns",
            "extra": "100 samples\n414 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 46.68,
            "range": "± 1.61896",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 16.6659,
            "range": "± 1.2252",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 126.143,
            "range": "± 3.40465",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 83.729,
            "range": "± 4.56701",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 969.698,
            "range": "± 24.5536",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 965.726,
            "range": "± 16.4387",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 151.259,
            "range": "± 4.46941",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 383.048,
            "range": "± 5.81001",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 45.4898,
            "range": "± 4.6926",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 45.004,
            "range": "± 4.39023",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.9147,
            "range": "± 2.89206",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.5034,
            "range": "± 2.24882",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 370.075,
            "range": "± 16.2171",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 369.41,
            "range": "± 10.3896",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 374.858,
            "range": "± 5.27331",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 343.468,
            "range": "± 4.51892",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 149.855,
            "range": "± 7.24581",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 153.196,
            "range": "± 12.1975",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 254.942,
            "range": "± 21.0212",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 239.251,
            "range": "± 24.7185",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 62.5933,
            "range": "± 0.960117",
            "unit": "ns",
            "extra": "100 samples\n506 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 48.9902,
            "range": "± 0.431276",
            "unit": "ns",
            "extra": "100 samples\n646 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 59.1074,
            "range": "± 1.2195",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 15.0417,
            "range": "± 726.753",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 93.2015,
            "range": "± 3.05454",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 30.2349,
            "range": "± 2.49279",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip construct",
            "value": 72.0148,
            "range": "± 3.69419",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 70.9974,
            "range": "± 3.74746",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 159.663,
            "range": "± 19.2815",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 419.968,
            "range": "± 27.2494",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 65.9599,
            "range": "± 3.68665",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 65.43,
            "range": "± 1.60935",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 60.8224,
            "range": "± 1.56382",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 60.9532,
            "range": "± 2.12944",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 154.31,
            "range": "± 9.30915",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 153.656,
            "range": "± 10.2152",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 144.502,
            "range": "± 1.67626",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 110.305,
            "range": "± 2.36575",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip accumulate",
            "value": 1904.15,
            "range": "± 6679.57",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1904.6499999999999,
            "range": "± 6354.8",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4406.08,
            "range": "± 213144",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4415.33,
            "range": "± 196274",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1071.5,
            "range": "± 7006.87",
            "unit": "ns",
            "extra": "100 samples\n261 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 768.82,
            "range": "± 3.9181",
            "unit": "ns",
            "extra": "100 samples\n362 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 347.364,
            "range": "± 2.97877",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 128.131,
            "range": "± 3.50528",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 469.676,
            "range": "± 4.86153",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 335.249,
            "range": "± 6.4714",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2065.5899999999997,
            "range": "± 12785.8",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2064.18,
            "range": "± 20354",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 338.774,
            "range": "± 5.80415",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 884.15,
            "range": "± 5.55407",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 248.9,
            "range": "± 2.60048",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 248.309,
            "range": "± 1.65965",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 261.253,
            "range": "± 1.60786",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 261.197,
            "range": "± 1.49977",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1901.68,
            "range": "± 4494.06",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1905.94,
            "range": "± 9486.94",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1884.3000000000002,
            "range": "± 9889.24",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1638.8700000000001,
            "range": "± 3953.1800000000003",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}